#include "personaldevcontrol.h"
#include "apimongo.h"
#include <QDateTime>
#include <QTimer>

PersonalDevControl::PersonalDevControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PersonalDevControlClass())
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PersonalDevControl::updateTime);
    connect(timer2, &QTimer::timeout, this, &PersonalDevControl::updateClock);
    timer2->start(1000);
    connect(ui->startButton, &QPushButton::clicked, this, &PersonalDevControl::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &PersonalDevControl::stopTimer);
    //connect(ui->sendButton, &QPushButton::clicked, this, &testeMongo::sendbtn_clicked);
    //connect(ui->clearButton, &QPushButton::clicked, this, &testeMongo::clearbtn_clicked);
    ui->stopButton->setStyleSheet("background-color: rgb(221, 160, 221);color: rgb(255, 255, 255); ");
    ui->hora_label->setText("00:00:00");
}

PersonalDevControl::~PersonalDevControl()
{
    delete ui;
}

void PersonalDevControl::onLoginSuccessful(const QString& logresult) {
    userInfo = logresult; // Armazena a informação do login
}

void PersonalDevControl::sendbtn_clicked()
{
    string resultado = API_Client.do_find();
    QString resultString = QString::fromStdString(resultado);
    ui->textEdit->setText(resultString);
    //ui->textEdit->setText("Enviado.");
}

void PersonalDevControl::clearbtn_clicked()
{
    ui->textEdit->setText("");
}


void PersonalDevControl::startTimer()
{
    timer->start(1000); // Atualiza a cada segundo
    ui->stopButton->setEnabled(true);
    ui->stopButton->setStyleSheet("background-color: rgb(128,0,128);color: rgb(255, 255, 255); ");
    ui->startButton->setEnabled(false);
    ui->startButton->setStyleSheet("background-color: rgb(221, 160, 221);color: rgb(255, 255, 255); ");
}

void PersonalDevControl::stopTimer()
{
    timer->stop();
    ui->stopButton->setEnabled(false);
    ui->stopButton->setStyleSheet("background-color: rgb(221, 160, 221);color: rgb(255, 255, 255); ");
    ui->startButton->setEnabled(true);
    ui->startButton->setStyleSheet("background-color: rgb(128,0,128);color: rgb(255, 255, 255); ");
}

void PersonalDevControl::updateTime()
{
    elapsedSeconds++;
    QTime time = QTime(0, 0).addSecs(elapsedSeconds);
    ui->hora_label->setText(time.toString("hh:mm:ss"));
}
void PersonalDevControl::updateClock() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString currentTimeStr = currentTime.toString("hh:mm:ss");
    ui->clock_label->setText("Hora atual: " + currentTimeStr);
}