#pragma once
#include <string>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/collection.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/document.hpp>

using namespace std;

class MongoAPI {
public:
    MongoAPI();
    ~MongoAPI();

    std::string do_insert(const string& document, const string& collection="base0");
    std::string do_insertMany();
    std::string do_find(const string& collection = "base0");
    std::string do_findOne(const std::string& filter, const string& collection = "base0");
    std::string do_update(const std::string& filter, const std::string& up_data);
    std::string do_updateMany(const std::string& filter, const std::string& up_data);
    std::string do_deleteMany(const std::string& filter);
    std::string do_delete(const std::string& filter);

    static std::string replaceCollection(const std::string& json, const std::string& newCollection);

private:
    static mongocxx::instance instance_;
    mongocxx::client client_;
    mongocxx::database db_;
    
    // Helper methods
    bsoncxx::document::value parseJsonToDocument(const std::string& json);
    std::string documentToJson(const bsoncxx::document::view& doc);
};

