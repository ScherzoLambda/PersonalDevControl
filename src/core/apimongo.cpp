#include <iostream>
#include <string>
#include <cstdlib>
#include <QMessageBox>
#include "apimongo.h"
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <mongocxx/exception/exception.hpp>

using namespace std;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;

// Static instance for MongoDB driver
mongocxx::instance MongoAPI::instance_{};

MongoAPI::MongoAPI()
{
    try {
        
        const char* mongo_uri = std::getenv("MONGODB_URI");
        std::string uri_string;
        
        if (mongo_uri) {
            uri_string = mongo_uri;
        } else {
            // Default connection string for development (should be set via environment in production)
            uri_string = "mongodb+srv://agora_user:Ow9q1Icba6oA7l8t@cluster0.oitlzz4.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0";
            std::cout << "Warning: Using default MongoDB URI. Set MONGODB_URI environment variable for production." << std::endl;
        }
        
        client_ = mongocxx::client{mongocxx::uri{uri_string}};
        db_ = client_["p_dev_control"];
        
        // Test connection
        auto ping_cmd = bsoncxx::builder::basic::make_document(
            bsoncxx::builder::basic::kvp("ping", 1)
        );
        db_.run_command(ping_cmd.view());
        std::cout << "Successfully connected to MongoDB!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "MongoDB connection error: " << e.what() << std::endl;
    }
}

MongoAPI::~MongoAPI() {
    // mongocxx handles cleanup automatically
}

// Helper method to parse JSON string to BSON document
bsoncxx::document::value MongoAPI::parseJsonToDocument(const std::string& json) {
    try {
        return bsoncxx::from_json(json);
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing JSON to BSON: " << e.what() << std::endl;
        // Return empty document on error
        return bsoncxx::builder::basic::make_document();
    }
}

// Helper method to convert BSON document to JSON string
std::string MongoAPI::documentToJson(const bsoncxx::document::view& doc) {
    try {
        return bsoncxx::to_json(doc);
    }
    catch (const std::exception& e) {
        std::cerr << "Error converting BSON to JSON: " << e.what() << std::endl;
        return "{}";
    }
}

// Function to replace collection name in JSON (keeping for compatibility)
string MongoAPI::replaceCollection(const std::string& json, const std::string& newCollection) {
    std::string result = json;
    std::string search = "\"collection\":\"";
    std::size_t startPos = result.find(search);

    if (startPos != std::string::npos) {
        std::size_t endPos = result.find("\"", startPos + search.length());
        if (endPos != std::string::npos) {
            result.replace(startPos + search.length(), endPos - (startPos + search.length()), newCollection);
        }
    }
    return result;
}

string MongoAPI::do_insert(const string& document, const string& collection) {
    try {
        mongocxx::collection coll = db_[collection];
        
        // Parse the document string that comes in the old format like:
        // ",\"document\":{\"nome\": \"test\", \"email\": \"test@test.com\", ...}"
        // We need to extract just the document part
        
        std::string doc_json = document;
        
        // First, try to find the document object specifically
        size_t doc_start = doc_json.find("{\"nome\":");
        if (doc_start == std::string::npos) {
            doc_start = doc_json.find("{\"id_usuario\":");
        }
        if (doc_start == std::string::npos) {
            // Try to find any JSON object start
            doc_start = doc_json.find("{");
        }
        
        if (doc_start != std::string::npos) {
            // Find the matching closing brace
            int brace_count = 0;
            size_t doc_end = doc_start;
            for (size_t i = doc_start; i < doc_json.length(); i++) {
                if (doc_json[i] == '{') brace_count++;
                if (doc_json[i] == '}') brace_count--;
                if (brace_count == 0) {
                    doc_end = i;
                    break;
                }
            }
            doc_json = doc_json.substr(doc_start, doc_end - doc_start + 1);
        } else {
            std::cerr << "Could not find valid JSON in document: " << document << std::endl;
            return "0";
        }
        
        std::cout << "Parsed document JSON: " << doc_json << std::endl;
        auto doc = parseJsonToDocument(doc_json);
        auto result = coll.insert_one(doc.view());
        
        if (result) {
            return "Document inserted successfully with ID: " + result->inserted_id().get_oid().value.to_string();
        } else {
            return "0";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Insert error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_insertMany() {
    try {
        // This was not implemented in the original code either
        return "insertMany not implemented";
    }
    catch (const std::exception& e) {
        std::cerr << "InsertMany error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_find(const string& collection) {
    try {
        mongocxx::collection coll = db_[collection];
        auto cursor = coll.find({});
        
        std::string result = "{\"documents\":[";
        bool first = true;
        
        for (auto doc : cursor) {
            if (!first) {
                result += ",";
            }
            result += documentToJson(doc);
            first = false;
        }
        
        result += "]}";
        return result;
    }
    catch (const std::exception& e) {
        std::cerr << "Find error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_findOne(const string& filter, const string& collection) {
    try {
        mongocxx::collection coll = db_[collection];
        
        // Parse the filter string that comes in format like:
        // " ,\"filter\":{\"email\":\"test@test.com\",\"senha\":\"hashedpassword\"}"
        std::string filter_json = filter;
        
        // First, try to find the filter object specifically
        size_t filter_start = filter_json.find("{\"email\":");
        if (filter_start == std::string::npos) {
            // Look for any other field patterns
            filter_start = filter_json.find("{\"");
        }
        if (filter_start == std::string::npos) {
            // Just look for the first opening brace
            filter_start = filter_json.find("{");
        }
        
        if (filter_start != std::string::npos) {
            // Find the matching closing brace
            int brace_count = 0;
            size_t filter_end = filter_start;
            for (size_t i = filter_start; i < filter_json.length(); i++) {
                if (filter_json[i] == '{') brace_count++;
                if (filter_json[i] == '}') brace_count--;
                if (brace_count == 0) {
                    filter_end = i;
                    break;
                }
            }
            filter_json = filter_json.substr(filter_start, filter_end - filter_start + 1);
        } else {
            // If no valid JSON found, create an empty filter to find any document
            filter_json = "{}";
        }
        
        std::cout << "Parsed filter JSON: " << filter_json << std::endl;
        auto filter_doc = parseJsonToDocument(filter_json);
        auto result = coll.find_one(filter_doc.view());
        
        if (result) {
            return documentToJson(result->view());
        } else {
            return "0";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "FindOne error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_update(const string& filter, const string& up_data, const string& collection) {
    try {
        mongocxx::collection coll = db_[collection];
        
        // Parse filter and update data from the combined string
        // The format is usually filter + up_data combined
        auto filter_doc = parseJsonToDocument(filter);
        auto update_doc = parseJsonToDocument(up_data);
        
        auto result = coll.update_one(filter_doc.view(), update_doc.view());
        
        if (result && result->modified_count() > 0) {
            return "Document updated successfully";
        } else {
            return "0";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Update error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_updateMany(const std::string& filter, const std::string& up_data) {
    try {
        mongocxx::collection coll = db_["base0"];
        
        auto filter_doc = parseJsonToDocument(filter);
        auto update_doc = parseJsonToDocument(up_data);
        
        auto result = coll.update_many(filter_doc.view(), update_doc.view());
        
        if (result && result->modified_count() > 0) {
            return "Documents updated successfully. Count: " + std::to_string(result->modified_count());
        } else {
            return "0";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "UpdateMany error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_deleteMany(const std::string& filter) {
    try {
        mongocxx::collection coll = db_["base0"];
        
        auto filter_doc = parseJsonToDocument(filter);
        auto result = coll.delete_many(filter_doc.view());
        
        if (result && result->deleted_count() > 0) {
            return "Documents deleted successfully. Count: " + std::to_string(result->deleted_count());
        } else {
            return "0";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "DeleteMany error: " << e.what() << std::endl;
        return "0";
    }
}

string MongoAPI::do_delete(const std::string& filter) {
    try {
        mongocxx::collection coll = db_["base0"];
        
        auto filter_doc = parseJsonToDocument(filter);
        auto result = coll.delete_one(filter_doc.view());
        
        if (result && result->deleted_count() > 0) {
            return "Document deleted successfully";
        } else {
            return "0";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Delete error: " << e.what() << std::endl;
        return "0";
    }
}
