/********************************************************************************
** Form generated from reading UI file 'loginMongoNCAqhs.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINMONGONCAQHS_H
#define LOGINMONGONCAQHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginTasks
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QFrame *LoginTasks)
    {
        if (LoginTasks->objectName().isEmpty())
            LoginTasks->setObjectName("LoginTasks");
        LoginTasks->resize(433, 200);
        LoginTasks->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 115, 158);"));
        verticalLayout_2 = new QVBoxLayout(LoginTasks);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(LoginTasks);
        label_3->setObjectName("label_3");
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font.setPointSize(18);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(LoginTasks);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font1.setPointSize(14);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(LoginTasks);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(LoginTasks);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_2 = new QLineEdit(LoginTasks);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lineEdit_2);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(LoginTasks);
        pushButton->setObjectName("pushButton");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font2.setPointSize(11);
        font2.setBold(true);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(128,0,128);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(LoginTasks);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128,0,128);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_2);


        retranslateUi(LoginTasks);

        QMetaObject::connectSlotsByName(LoginTasks);
    } // setupUi

    void retranslateUi(QFrame *LoginTasks)
    {
        LoginTasks->setWindowTitle(QCoreApplication::translate("LoginTasks", "Login Tasks", nullptr));
        label_3->setText(QCoreApplication::translate("LoginTasks", "PersonalDevControl", nullptr));
        label->setText(QCoreApplication::translate("LoginTasks", "Email:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginTasks", "Senha:", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginTasks", "Entrar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginTasks", "Registrar-se", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginTasks: public Ui_LoginTasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINMONGONCAQHS_H
