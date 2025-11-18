#include <models/modelUser.hpp>
#include <QString>
#include <QCryptographicHash>   

// TODO: usar  nlohmann/json 

string ModelUser::criptPassword(QString pass) {

    // Converta a senha para QByteArray
    QByteArray byteArrayPassword = pass.toUtf8();

    // Calcule o hash SHA-256 da senha
    QByteArray hashBytes = QCryptographicHash::hash(byteArrayPassword, QCryptographicHash::Sha256);

    // Converta o hash para QString
    QString hashedPassword = QString(hashBytes.toHex());

    return hashedPassword.toStdString();
}

string ModelUser::document_user(const string& nome, const string& email, const string& senha, const string& horas_trabalhadas=" ")
{
    string documento = ",\"document\":{\"nome\": \"" + nome + "\", \"email\": \"" + email + "\",\"senha\": \"" + senha + "\",\"horas_trabalhadas\": \"" + horas_trabalhadas + "\"}";
    return documento;
}


string ModelUser::login_filter(const string& email, const string& senha)
{
    string filter = " ,\"filter\":{\"email\":\""+ email +"\",\"senha\":\"" + senha + "\"}";
    return filter;
}
