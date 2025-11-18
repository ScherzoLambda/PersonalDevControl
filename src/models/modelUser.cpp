#include <models/modelUser.hpp>
#include <QString>
#include <QCryptographicHash>

// ---------------------------------------------------------------------------
// HASH DE SENHA
// ---------------------------------------------------------------------------
string ModelUser::criptPassword(QString pass)
{
    QByteArray byteArrayPassword = pass.toUtf8();
    QByteArray hashBytes = QCryptographicHash::hash(byteArrayPassword, QCryptographicHash::Sha256);
    QString hashedPassword = QString(hashBytes.toHex());
    return hashedPassword.toStdString();
}

// ---------------------------------------------------------------------------
// SERIALIZAÇÃO (User -> JSON)
// ---------------------------------------------------------------------------
json User::to_json() const
{
    json j;
    j["document"] = {
        {"nome", nome},
        {"email", email},
        {"senha", senha},
        {"horas_trabalhadas", horas_trabalhadas}
    };
    return j;
}

// ---------------------------------------------------------------------------
// DESSERIALIZAÇÃO (JSON -> User)
// ---------------------------------------------------------------------------
User User::from_json(const json& j)
{
    User u;
    const json& d = j.at("document");

    u.nome = d.value("nome", "");
    u.email = d.value("email", "");
    u.senha = d.value("senha", "");
    u.horas_trabalhadas = d.value("horas_trabalhadas", "");

    return u;
}

// ---------------------------------------------------------------------------
// CRIA DOCUMENTO DO USUÁRIO
// ---------------------------------------------------------------------------
string ModelUser::document_user(const User& user)
{
    return user.to_json().dump();
}

// ---------------------------------------------------------------------------
// FILTRO PARA LOGIN
// ---------------------------------------------------------------------------
string ModelUser::login_filter(const string& email, const string& senha)
{
    json filter;
    filter["filter"] = {
        {"email", email},
        {"senha", senha}
    };

    return filter.dump();
}
