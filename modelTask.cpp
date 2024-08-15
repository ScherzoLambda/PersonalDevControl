#include "modelTask.h"
#include <QString>
#include <QCryptographicHash>]

using namespace std;

string ModelTask::criptPassword(QString pass) {

    // Converta a senha para QByteArray
    QByteArray byteArrayPassword = pass.toUtf8();

    // Calcule o hash SHA-256 da senha
    QByteArray hashBytes = QCryptographicHash::hash(byteArrayPassword, QCryptographicHash::Sha256);

    // Converta o hash para QString
    QString hashedPassword = QString(hashBytes.toHex());

    // Imprima o hash resultante
    //std::cout << "Senha criptografada: " << hashedPassword.toStdString() << std::endl;

    return hashedPassword.toStdString();
}

string ModelTask::document_user(const string& nome, const string& email, const string& senha, const string& horas_trabalhadas=" ")
{
    string documento = ",\"document\":{\"nome\": \"" + nome + "\", \"email\": \"" + email + "\",\"senha\": \"" + senha + "\",\"horas_trabalhadas\": \"" + horas_trabalhadas + "\"}";
    return documento;
}

string ModelTask::document_task(const string& id, const string& tipo, const string& descricao, const string& total, const string& inicio, const string& fim)
{   
    //string documento = ",\"document\":{\"id_usuario\": \"" + id + "\", \"tipo_task\": \"" + tipo + "\",\"desc_task\": \"" + descricao + "\", \"horas_gastas\": \"" + total + "\", \"hora_inicio\": \""+ inicio + ", \"hora_fim\": \"" + fim + "\"}";
    string documento = ",\"document\":{\"id_usuario\": \"" + id + "\", \"tipo_task\": \"" + tipo + "\",\"desc_task\": \"" + descricao + "\",\"horas_gastas\": \"" + total + "\"";
    documento = documento + ", \"hora_inicio\": \"" + inicio + "\",\"hora_fim\": \"" + fim + "\"}";
    return documento;
}

string ModelTask::login_filter(const string& email, const string& senha)
{
    // Corpo da requisição
    string filter = " ,\"filter\":{\"email\":\""+ email +"\",\"senha\":\"" + senha + "\"}";
    return filter;
}
string ModelTask::user_filter(const string& email)
{
    // Corpo da requisição
    string filter = " ,\"filter\":{\"email\":\""+ email +"\"}";
    return filter;
}
