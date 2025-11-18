#pragma once
#include <core/apimongo.hpp>
#include <string>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginTasks; }
QT_END_NAMESPACE

class LoginWindow : public QFrame
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget* parent = nullptr);
    ~LoginWindow();
    int checkresult(const std::string& data_result, const std::string& valuate);

signals:
    void loginSuccessful(const QString& logresult);

private slots:
    void onLoginButtonClicked();
    void onRegisterButtonClicked();

private:
    Ui::LoginTasks* ui;
    MongoAPI API_Client;
};