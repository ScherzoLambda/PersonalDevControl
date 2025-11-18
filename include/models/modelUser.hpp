#ifndef MODELUSER_H
#define MODELUSER_H

#include <string>
#include <QString>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct User {
    string nome;
    string email;
    string senha;
    string horas_trabalhadas;

    // Serialização (C++ → JSON)
    json to_json() const;

    // Desserialização (JSON → C++)
    static User from_json(const json& j);
};

class ModelUser {
public:
    static string criptPassword(QString pass);

    // Cria JSON do usuário completo
    static string document_user(const User& user);

    // Cria filtro para login
    static string login_filter(const string& email, const string& senha);
};

#endif // MODELUSER_H
