#include "personaldevcontrol.h"
#include "apimongo.h"
#include "modelTask.h"
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>
/// ============================================ Cosntrutor e Destrutor

PersonalDevControl::PersonalDevControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PersonalDevControlClass())
{
    ui->setupUi(this);
    elapsedSeconds = 0;
    locker_ = true;
    fistTime = true;
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    elapsedTime = new QElapsedTimer();

    connect(timer, &QTimer::timeout, this, &PersonalDevControl::updateTime); // contador de tempo gasto.
    connect(timer2, &QTimer::timeout, this, &PersonalDevControl::updateClock); // hora atual
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
/// ============================================ Métodos da aplicação

void PersonalDevControl::CalculateAndReplaceTimeSpend(QString time_spended_so_far_){

}

void PersonalDevControl::onLoginSuccessful(const QString& logresult) {
    userInfo = logresult; // Armazena a informação do user apos login
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
    elapsedTime->start();
    ui->stopButton->setEnabled(true);
    ui->stopButton->setStyleSheet("background-color: rgb(128,0,128);color: rgb(150, 150, 150); ");
    ui->startButton->setEnabled(false);
    ui->startButton->setStyleSheet("background-color: rgb(150, 150, 150);color: rgb(255, 255, 255); ");
    if(fistTime){ ui->textEdit->setText("Bem vindo de Volta!! Tenha uma otima produção!!"); fistTime = false;}
    else { ui->textEdit->setText("Bem vindo de Volta!! Bora Continuar?"); }

}

void PersonalDevControl::stopTimer()
{
    timer->stop();
    ui->stopButton->setEnabled(false);
    ui->stopButton->setStyleSheet("background-color: rgb(150, 150, 150);color: rgb(255, 255, 255); ");
    ui->startButton->setEnabled(true);
    ui->startButton->setStyleSheet("background-color: rgb(128,0,128);color: rgb(255, 255, 255); ");
    updateTimeSpendLabel(ui->hora_label->text());
}

void PersonalDevControl::updateTimeSpendLabel(QString time_spended_so_far) {
    QString tempoNoLabel = ui->label->text();

    QString tempoAtual = tempoNoLabel.left(8);

    // Converte as strings de tempo para objetos QTime
    QTime timeSpentSoFar = QTime::fromString(time_spended_so_far, "hh:mm:ss");
    QTime timeOnLabel = QTime::fromString(tempoAtual, "hh:mm:ss");
    /*
    // Soma os tempos
    QTime novoTempoTotal = timeOnLabel.addSecs(timeSpentSoFar.hour() * 3600 +
        timeSpentSoFar.minute() * 60 +
        timeSpentSoFar.second());
     */
    // Atualiza o label com o novo tempo total
    ui->label->setText(timeSpentSoFar.toString("hh:mm:ss")+" de 30H");
    string doc = ModelTask::document_task("", "", "", "", "inicio", "fim");
    //QMessageBox::information(this, "Sucesso", QString::fromStdString(doc));
    string statusTransaction = API_Client.do_insert(
        doc,"users_task");
    if (statusTransaction != "0") {
        //QMessageBox::information(this, "Sucesso", QString::fromStdString(statusTransaction));
        ui->textEdit->setText("Intervalo começou!!");
    }
}

/**
* @brief Atualiza o tempo gasto/decorrido
*/
void PersonalDevControl::updateTime()
{
    locker_ = true;
    while(locker_){
        elapsedSeconds++;
        locker_ = false;
    }
    
    QTime time = QTime(0, 0).addSecs(elapsedSeconds);
    ui->hora_label->setText(time.toString("hh:mm:ss"));
}
/**
* @brief Atualiza a hora atual
*/
void PersonalDevControl::updateClock() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString currentTimeStr = currentTime.toString("hh:mm:ss");
    
    // verifica Se é o inicio de um novo dia, para resetar o contador de horas diarias
    if (currentTimeStr.startsWith("00:00:00")) { if (!locker_) { elapsedSeconds = 0; } ui->hora_label->setText("00:00:00"); }
    ui->clock_label->setText("Hora atual: " + currentTimeStr);
}