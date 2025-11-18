#pragma once
#include <core/apimongo.hpp>
#include <QtWidgets/QMainWindow>

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
    void updateClock();
    void stopTimer();
    void startTimer();
    void onStopButtonClicked();

public slots:
    void onLoginSuccessful(const QString& logresult);

private:
    Ui::PersonalDevControlClass *ui;
    QTimer* timer;
    QTimer* timer2;
    int elapsedSeconds;
    MongoAPI API_Client;
    QString userInfo;
};
