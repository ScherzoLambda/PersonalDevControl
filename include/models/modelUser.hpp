#ifndef MODELUSER_H
#define MODELUSER_H

#include <string>
#include <QString>

// TODO: usar  nlohmann/json 
using namespace std;
class ModelUser {
public:
    static string criptPassword(QString pass);
    static string document_user(const string& nome, const string& email, const string& senha, const string& horas_trabalhadas);
    static string login_filter(const string& email, const string& senha);
};
#endif // MODELUSER_H