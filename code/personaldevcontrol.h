#pragma once
#include "apimongo.h"
#include <QtWidgets/QMainWindow>
#include "ui_personaldevcontrol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PersonalDevControlClass; };
QT_END_NAMESPACE

class PersonalDevControl : public QMainWindow
{
    Q_OBJECT

public:
    PersonalDevControl(QWidget *parent = nullptr);
    ~PersonalDevControl();

    void sendbtn_clicked();
    void clearbtn_clicked();
    void updateTime();
    void updateTimeSpendLabel(QString time_spended_so_far);
    void CalculateAndReplaceTimeSpend(QString time_spended_so_far_);
    void updateClock();
    void stopTimer();
    void startTimer();

public slots:
    void onLoginSuccessful(const QString& logresult);

private:
    Ui::PersonalDevControlClass *ui;
    QTimer* timer;
    QElapsedTimer* elapsedTime;
    QTimer* timer2;
    int elapsedSeconds;
    MongoAPI API_Client;
    QString userInfo;
    boolean locker_;
    boolean fistTime;
};
