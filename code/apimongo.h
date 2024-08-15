#pragma once
#include <string>
#include <curl/curl.h>
using namespace std;
class MongoAPI {
public:
    MongoAPI();
    ~MongoAPI();

    CURL* curl;
    CURLcode res;

    string make_request(string reqURL);
    std::string do_insert(const string& document, const string& collection="base0");
    std::string do_insertMany();
    std::string do_find(const string& collection = "base0");
    std::string do_findOne(const std::string& filter, const string& collection = "base0");
    std::string do_update(const std::string& filter, const std::string& up_data);
    std::string do_updateMany(const std::string& filter, const std::string& up_data);
    std::string do_deleteMany(const std::string& filter);
    std::string do_delete(const std::string& filter);

    static std::string replaceCollection(const std::string& json, const std::string& newCollection);
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response);

private:
    std::string url;

    std::string response_data;
    struct curl_slist* headers;
    std::string body;
};

