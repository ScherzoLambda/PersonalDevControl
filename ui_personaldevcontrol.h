/********************************************************************************
** Form generated from reading UI file 'personaldevcontrolAdWAZm.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PERSONALDEVCONTROLADWAZM_H
#define PERSONALDEVCONTROLADWAZM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalDevControlClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *clock_label;
    QLabel *label;
    QTextEdit *textEdit_2;
    QLabel *hora_label;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *PersonalDevControlClass)
    {
        if (PersonalDevControlClass->objectName().isEmpty())
            PersonalDevControlClass->setObjectName("PersonalDevControlClass");
        PersonalDevControlClass->resize(400, 300);
        PersonalDevControlClass->setMaximumSize(QSize(400, 300));
        PersonalDevControlClass->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 115, 158);"));
        centralWidget = new QWidget(PersonalDevControlClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        clock_label = new QLabel(centralWidget);
        clock_label->setObjectName("clock_label");
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font.setItalic(true);
        clock_label->setFont(font);
        clock_label->setStyleSheet(QString::fromUtf8("background-color: rgb(220,220,220);"));
        clock_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(clock_label, 1, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font1.setPointSize(8);
        font1.setBold(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(220,220,220);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMinimumSize(QSize(0, 25));
        textEdit_2->setMaximumSize(QSize(16777215, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        textEdit_2->setFont(font2);
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(220,220,220);\n"
""));

        gridLayout->addWidget(textEdit_2, 2, 0, 1, 3);

        hora_label = new QLabel(centralWidget);
        hora_label->setObjectName("hora_label");
        hora_label->setMinimumSize(QSize(180, 95));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font3.setPointSize(26);
        hora_label->setFont(font3);
        hora_label->setStyleSheet(QString::fromUtf8("background-color: rgb(220,220,220);"));
        hora_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(hora_label, 3, 2, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(0, 100));
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        textEdit->setFont(font2);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        textEdit->setFrameShape(QFrame::Shape::StyledPanel);

        gridLayout->addWidget(textEdit, 4, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(80, 85));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font4.setPointSize(12);
        font4.setBold(true);
        startButton->setFont(font4);
        startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(128,0,128);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(80, 85));
        stopButton->setFont(font4);
        stopButton->setStyleSheet(QString::fromUtf8("background-color: rgb(128,0,128);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(stopButton);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);

        PersonalDevControlClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PersonalDevControlClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        PersonalDevControlClass->setMenuBar(menuBar);

        retranslateUi(PersonalDevControlClass);

        QMetaObject::connectSlotsByName(PersonalDevControlClass);
    } // setupUi

    void retranslateUi(QMainWindow *PersonalDevControlClass)
    {
        PersonalDevControlClass->setWindowTitle(QCoreApplication::translate("PersonalDevControlClass", "PersonalDevControl", nullptr));
        clock_label->setText(QString());
        label->setText(QCoreApplication::translate("PersonalDevControlClass", "00:00:00 de 30H", nullptr));
        textEdit_2->setPlaceholderText(QCoreApplication::translate("PersonalDevControlClass", "Task Tittle", nullptr));
#if QT_CONFIG(statustip)
        hora_label->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        hora_label->setText(QString());
        startButton->setText(QCoreApplication::translate("PersonalDevControlClass", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("PersonalDevControlClass", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonalDevControlClass: public Ui_PersonalDevControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PERSONALDEVCONTROLADWAZM_H
