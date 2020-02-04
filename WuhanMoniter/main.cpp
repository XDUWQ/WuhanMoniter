#include "mainwindow.h"
#include "logindialog.h"
#include "conndlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    LoginDialog *logindialog = new LoginDialog;
//    if(logindialog->exec()==QDialog::Accepted){//正确输入用户名和密码
//        ConnDlg dialog;
//        if(dialog.exec()!=QDialog::Accepted){
//            qDebug()<<QStringLiteral("数据库未能正常运行")<<endl;
//            return -1;
//        }
//        MainWindow w;
//        w.show();
//        return a.exec();
//    }
//    return 0;

    //调式部分
    ConnDlg dialog;
    dialog.exec();
    MainWindow w;
    w.show();
    return a.exec();
}
