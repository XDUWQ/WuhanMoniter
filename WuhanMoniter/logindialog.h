#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    //初始化用户名和密码
    QString m_user="xdu";
    QString m_pswd = "123456";


private slots:
    void on_CancleBtn_clicked();
    void on_OkBtn_clicked();
    void on_Prompt_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
