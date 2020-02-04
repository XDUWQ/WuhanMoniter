#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("icon.png"));
    setWindowTitle(QStringLiteral("登录窗口"));
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);//设置默认为密码输入方式
    this->setAttribute(Qt::WA_DeleteOnClose);//设置为关闭时删除
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//取消键关闭窗口
void LoginDialog::on_CancleBtn_clicked()
{
    this->close();
}

//按下确定键
void LoginDialog::on_OkBtn_clicked()
{
    QString user = ui->UserEidt->text().trimmed();
    QString pswd = ui->PasswordEdit->text().trimmed();
    if((user==m_user)&&(pswd==m_pswd)){
        this->accept();//
    }else if((user==m_user)&&(pswd!=m_pswd)){
        QMessageBox::warning(this,QStringLiteral("错误提示"),QStringLiteral("密码错误！\n请重新输入！"));
    }else if((user!=m_user)&&(pswd==m_pswd)){
        QMessageBox::warning(this,QStringLiteral("错误提示"),QStringLiteral("用户名错误！\n请重新输入！"));
    }else{
        QMessageBox::warning(this,QStringLiteral("错误提示"),QStringLiteral("用户名和密码均错误！\n请重新输入！"));
    }
}

//提示键
void LoginDialog::on_Prompt_clicked()
{
    QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("如果忘记密码\n请联系开发者\n15385433870@163.com"));
}

//勾选显示密码后
void LoginDialog::on_checkBox_stateChanged(int arg1)
{
    if(arg1==2||arg1==1){
         ui->PasswordEdit->setEchoMode(QLineEdit::Normal);
    }else{
        ui->PasswordEdit->setEchoMode(QLineEdit::Password);
    }
}
