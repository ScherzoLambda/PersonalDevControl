#include "loginmongo.h"
#include "apimongo.h"
#include "modelTask.h"
#include "ui_loginMongo.h"
#include <iostream>
#include <QMessageBox>
#include <QFormLayout>

LoginWindow::LoginWindow(QWidget* parent) :
    QFrame(parent),
    ui(new Ui::LoginTasks)
{
    ui->setupUi(this);

    // Connect the login button clicked signal to the slot
    connect(ui->pushButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoginWindow::onRegisterButtonClicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
/*
* @brief
*   Checa resultado da request \n
*
*   Verifica se o email foi encontrado ou não.
*/
int LoginWindow::checkresult(const string& data_result, const string& valuate)
{

    if (data_result.find(valuate) != std::string::npos) {
        return 1;
        //std::cout << "Email encontrado!" << std::endl;
    }
    else {
        return 0;
        //std::cout << "Email não encontrado." << std::endl;
    }
}

/*
* @brief
*   Captura evento de clique no botão "Registrar-se" \n
*
*   Abre dialogo com os campos necessarios para o registro.
*   e efetua o registro.
*/
void LoginWindow::onRegisterButtonClicked()
{
    // Criar um novo diálogo/modal para registro de usuário
    QDialog registrationDialog;
    registrationDialog.setWindowTitle("Registro de Usuário");
    registrationDialog.setFixedSize(400, 150);
    registrationDialog.setStyleSheet("background-color: rgb(151, 115, 158);");

    // Adicionar campos de entrada para nome, email e senha
    QLineEdit* nameEdit = new QLineEdit(&registrationDialog);
    QLineEdit* emailEdit = new QLineEdit(&registrationDialog);
    QLineEdit* passwordEdit = new QLineEdit(&registrationDialog);
    passwordEdit->setEchoMode(QLineEdit::Password);

    nameEdit->setStyleSheet("background-color: rgb(255, 255, 255);");
    emailEdit->setStyleSheet("background-color: rgb(255, 255, 255);");
    passwordEdit->setStyleSheet("background-color: rgb(255, 255, 255);");

    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Nome:", nameEdit);
    formLayout->addRow("Email:", emailEdit);
    formLayout->addRow("Senha:", passwordEdit);

    // Adicionar botões de registro e cancelar
    QPushButton* registerButton = new QPushButton("Registrar-se", &registrationDialog);
    QPushButton* cancelButton = new QPushButton("Cancelar", &registrationDialog);
    // Definir a política de tamanho para que ambos os botões tenham o mesmo tamanho
    registerButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    cancelButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    registerButton->setStyleSheet("background-color: rgb(128,0,128);font-size: 14px;color:white;font-weight:bold;");
    cancelButton->setStyleSheet("background-color: rgb(128,0,128);font-size: 14px; color:white; font-weight:bold;");

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(registerButton);
    buttonLayout->addWidget(cancelButton);

    // Usar QVBoxLayout para organizar tudo verticalmente
    QVBoxLayout* mainLayout = new QVBoxLayout(&registrationDialog);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    
    // Conectar os cliques dos botões aos slots para processar o registro e o cancelamento
    connect(registerButton, &QPushButton::clicked, [&]() {
        // Obter valores dos campos de entrada
        QString name = nameEdit->text();
        QString email = emailEdit->text();
        QString password = passwordEdit->text();

        // Validar os dados (por exemplo, verificar se todos os campos estão preenchidos)
        if (name.isEmpty() || email.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(&registrationDialog, "Erro", "Por favor, preencha todos os campos.");
            return;
        }

        string hashedPassword = ModelTask::criptPassword(password);
        string status_register = API_Client.do_insert(ModelTask::document_user(name.toStdString(),email.toStdString(), hashedPassword,""),"users_1");
        if (status_register != "0") {
            QMessageBox::information(&registrationDialog, "Sucesso",QString::fromStdString(status_register));
            registrationDialog.close();
        }
        else {
            QMessageBox::information(&registrationDialog, "Falha na Operação", "Falha ao registar, tente novamente!");
        }

    });

    connect(cancelButton, &QPushButton::clicked, &registrationDialog, &QDialog::reject);
    registrationDialog.setLayout(mainLayout);
    //formLayout->addRow(cancelButton, registerButton);

    // Exibir o diálogo/modal de registro
    registrationDialog.exec();
}

/*
* @brief
*   Captura evento de clique no botão "Login" \n 
*   
*   Verifica os campos de email e senha
*   e efetua o login
*/
void LoginWindow::onLoginButtonClicked()
{
     
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    string nullDoc = " {\"document\":null}";

    
    if ((!username.isNull() || !username.isEmpty()) && (password.isNull() || !password.isEmpty())) {
        
        string hashedPassword = ModelTask::criptPassword(password);
        string logresult = API_Client.do_findOne(ModelTask::login_filter(username.toStdString(), hashedPassword), "users_1");
        
        if (logresult != nullDoc && checkresult(logresult, username.toStdString()) == 1) {
            QMessageBox::information(this, "Login bem-sucedido", "Seja Bem-Vindo " + username);
            emit loginSuccessful(QString::fromStdString(logresult));
            // Hide the login window (optional)
            this->hide();
        }
        else {
            //QMessageBox::warning(this, "Login Failed", "Invalid username or password" + QString::fromStdString(logresult));
            QMessageBox::warning(this, "Login Failed", "Invalid username or password");
        }
        
    }
    else {
        // Informando ao usuario que há campos vazios
        QMessageBox::warning(this, "Login Failed", "Há campos vazios");
    }
}
