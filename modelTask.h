#ifndef MODELTASK_H
#define MODELTASK_H

#include <string>
#include <QString>
using namespace std;
class ModelTask {
public:
    static string criptPassword(QString pass);
    static string document_user(const string& nome, const string& email, const string& senha, const string& horas_trabalhadas);
    static string document_task(const string& id, const string& tipo, const string& descricao, const string& total, const string& inicio, const string& fim);
    static string login_filter(const string& email, const string& senha);
    static string user_filter(const string& email);
};
#endif // MODELTASK_H