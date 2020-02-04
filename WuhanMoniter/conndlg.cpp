#include "conndlg.h"
#include "ui_conndlg.h"

ConnDlg::ConnDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnDlg)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("icon.png"));
    setWindowTitle(QStringLiteral("数据库连接"));
    QStringList drives = QSqlDatabase::drivers();//返回所有可用的驱动名
    ui->DriveEdit->addItems(drives);//添加到数据库名的扩展栏中
    //将选择的数据库名发射信号连接槽
    connect(ui->DriveEdit,SIGNAL(currentIndexChanged(const QString &)),this,
            SLOT(driverChanged(const QString &)));
}

ConnDlg::~ConnDlg()
{
    delete ui;
}

//关闭界面
void ConnDlg::on_cancelBtn_clicked()
{
    this->close();
}

//改变数据库种类
void ConnDlg::driverChanged(const QString &text){
    qDebug()<<QStringLiteral("数据库切换槽连接")<<endl;
    if(text=="QSQLITE"){//sqlite数据库，不需要设置用户名、密码、主机名、端口名称
        ui->HostEdit->setEnabled(false);
        ui->UsernameEdit->setEnabled(false);
        ui->PassawordEdit->setEnabled(false);
        ui->PortEdit->setEnabled(false);
        ui->DataLineEdit->setEnabled(false);
    }else{//其他数据库需要设置用户名、密码、主机名、端口名称
        ui->HostEdit->setEnabled(true);
        ui->UsernameEdit->setEnabled(true);
        ui->PassawordEdit->setEnabled(true);
        ui->PortEdit->setEnabled(true);
        ui->DataLineEdit->setEnabled(true);
    }
}

//获取驱动名称
QString ConnDlg::driverName() const{
    return ui->DriveEdit->currentText();
}

//获取数据库名
QString ConnDlg::databaseName() const{
    return ui->DataLineEdit->text();
}

//获取用户名
QString ConnDlg::userName() const{
    return ui->UsernameEdit->text();
}

//获取密码
QString ConnDlg::password() const{
    return ui->PortEdit->text();
}

//获取主机名
QString ConnDlg::hostName() const{
    return ui->PassawordEdit->text();
}

//获取端口名
int ConnDlg::port() const{
    return ui->PortEdit->value();
}

//链接键按下
void ConnDlg::on_connBtn_clicked()
{
    if(ui->DriveEdit->currentText().isEmpty()){
        ui->StatusLabel->setText(QStringLiteral("请选择一个数据库进行连接！"));
        ui->DriveEdit->setFocus();//将选择数据库栏设置为活动状态
    }else if(ui->DriveEdit->currentText()=="QSQLITE"){//如果是sqlite
        addsqliteConnect();//连接QSQLITE数据库
        createDB();//创建数据表
        accept();//隐藏对话框并将代码模式设置为已接受
    }else{
        QSqlError err = addConnection(driverName(),databaseName(),hostName(),userName(),password(),port());
        if(err.type()!=QSqlError::NoError){//创建数据库失败
            ui->StatusLabel->setText(err.text());//显示错误类型
        }else{//创建成功
            ui->StatusLabel->setText(QStringLiteral("创建数据库成功！"));
        }
        accept();
    }
}

//建立SQLite连接
void ConnDlg::addsqliteConnect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//创建sqlite数据表
    db.setDatabaseName("databasefile");
    if(!db.open()){//如果未能正常创建数据表
        ui->StatusLabel->setText(db.lastError().text());
        return;//终止程序
    }else{
        ui->StatusLabel->setText(QStringLiteral("成功创建SQLite数据库"));
    }
}

//建立非sqlite连接
QSqlError ConnDlg::addConnection(const QString &driver,const QString &dbName,const QString &host,const QString &user,const QString &passwd,int port){
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if(!db.open(user,passwd)){
        err = db.lastError();//记录最后一个错误，引用AAAAA默认数据库连接
    }
    return err;//返回错误信息
}

//创建数据表
void ConnDlg::createDB(){
    QSqlQuery query;
    query.exec("create table factory (id int primary key,manufactory varchar(40), address varchar(40))");

    query.exec("create table cars (carid int primary key, name varchar(50), factoryid int, year int, foreign key(factoryid) references factory(id))");

}
