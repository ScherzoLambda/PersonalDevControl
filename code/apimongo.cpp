#include <iostream>
#include <string>
#include <QMessageBox>
#include <curl/curl.h>
#include "apimongo.h"
using namespace std;

MongoAPI::MongoAPI()
    : url("https://sa-east-1.aws.data.mongodb-api.com/app/data-glsin/endpoint/data/v1"),
    headers(nullptr),
    body("{\"dataSource\":\"Cluster0\",\"database\":\"Server_DB\",\"collection\":\"users_1\"}")
{
    // Verifica se a inicialização do curl foi bem-sucedida
    if (!curl) {
        std::cerr << "Erro ao inicializar o libcurl" << std::endl;
    }
}

MongoAPI::~MongoAPI() {
    if (headers) {
        curl_slist_free_all(headers);
    }
    if (curl) {
        curl_easy_cleanup(curl);
    }
}

// Função para substituir o valor do campo "collection" no JSON
string MongoAPI::replaceCollection(const std::string& json, const std::string& newCollection) {
    std::string result = json;
    std::string search = "\"collection\":\"";
    std::size_t startPos = result.find(search);

    if (startPos != std::string::npos) {
        // Localiza a posição final do valor atual da coleção
        std::size_t endPos = result.find("\"", startPos + search.length());
        if (endPos != std::string::npos) {
            // Substitui o valor da coleção pelo novo valor
            result.replace(startPos + search.length(), endPos - (startPos + search.length()), newCollection);
        }
    }
    return result;
}

// Função de callback para receber os dados da resposta
size_t MongoAPI::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    response->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string MongoAPI::make_request(string reqURL)
{
    response_data = " ";
    curl = curl_easy_init();
    if (curl) {
        // Cabeçalhos da requisição
        headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "api-key: GkYXzrSsaEgankl5jLkJy2eA7eO5emqfGAb9xVwVvFQVzF1Szv1c6AkSDB39SOAQ");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Configura o método
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

        // Configura a URL
        curl_easy_setopt(curl, CURLOPT_URL, reqURL.c_str());

        // Configura a função de callback para receber os dados da resposta
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        // Faz a requisição
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Erro ao fazer a requisição: " << curl_easy_strerror(res) << std::endl;
            return "0";
        }
        else {
            // Exibe os dados da resposta
            return response_data;
        }

        // Limpa os cabeçalhos
        curl_slist_free_all(headers);
        // Finaliza o libcurl
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Erro ao inicializar o libcurl" << std::endl;
        return "Erro na biblioteca libcurl";
    }
}

string MongoAPI::do_insert(const string& document, const string& collection) {
    if(collection != "base0"){ body = replaceCollection(body, collection); }
    cout << body << endl;
    string insertUrl = url + "/action/insertOne";
    body.insert(body.size() - 1, document);
    return make_request(insertUrl);
}

string MongoAPI::do_insertMany()
{
    string insertManyUrl = url + "/action/insertMany";

    return make_request(insertManyUrl);

}

string MongoAPI::do_find(const string& collection) {
    if (collection != "base0") { body = replaceCollection(body, collection); }
    string findURL = url + "/action/find";
    return make_request(findURL);
}


string MongoAPI::do_findOne(const string& filter, const string& collection)
{
    if (collection != "base0") { body = replaceCollection(body, collection); }
    string findOne_URL = url + "/action/findOne";
    body.insert(body.size() - 1, filter);
    return make_request(findOne_URL);
}

string MongoAPI::do_update(const std::string& filter, const std::string& up_data)
{
    string update_url = url + "/action/updateOne";
    
    // Adiciona a string JSON ao corpo da requisição
    body.insert(body.size() - 1, filter); // Insere antes do último caractere '}
    body.insert(body.size() - 1, up_data);
    return make_request(update_url);
}

string MongoAPI::do_updateMany(const std::string& filter, const std::string& up_data)
{
    string updadeMany_url = url + "/action/updateMany";
    
    // Adiciona a string JSON ao corpo da requisição
    body.insert(body.size() - 1, filter); // Insere antes do último caractere '}
    body.insert(body.size() - 1, up_data);
    return make_request(updadeMany_url);
}

string MongoAPI::do_deleteMany(const std::string& filter)
{
    string deleteManyUrl = url + "/action/deleteMany";
    body.insert(body.size() - 1, filter);
    return make_request(deleteManyUrl);

}

string MongoAPI::do_delete(const std::string& filter)
{
    string deleteurl = url +"/action/deleteOne";
    
    body.insert(body.size() - 1, filter);
    return make_request(deleteurl);
}
