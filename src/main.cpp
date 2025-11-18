#include <ui/personaldevcontrol.hpp>
#include <ui/loginmongo.hpp>
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    PersonalDevControl w;
    LoginWindow log;
    // Connect the login success signal to showing the main window
    QObject::connect(&log, &LoginWindow::loginSuccessful, [&w](const QString& logresult) {
        w.onLoginSuccessful(logresult);
        w.show();
        });
    log.show();
    return a.exec();
}