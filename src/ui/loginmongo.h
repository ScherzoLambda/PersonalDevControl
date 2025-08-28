#pragma once
#include "ui_loginMongo.h"
#include "../core/apimongo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginTasks; }
QT_END_NAMESPACE

class LoginWindow : public QFrame
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget* parent = nullptr);
    ~LoginWindow();
    int checkresult(const string& data_result, const string& valuate);

signals:
    void loginSuccessful(const QString& logresult);

private slots:
    void onLoginButtonClicked();
    void onRegisterButtonClicked();

private:
    Ui::LoginTasks* ui;
    MongoAPI API_Client;
};
