#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("icon.png"));
    setWindowTitle(QStringLiteral("武汉疫情实时监控系统"));\

//    QGroupBox *Country = createCountryInfor();
//    QGroupBox *Hubei = createHubeiInfor();
//    QGroupBox *Wuhan = createWuhanInfor();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createCountryInfor(){
//    ui->CountryInfor->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置为进制用户编辑
//    ui->CountryInfor->setSelectionBehavior(QAbstractItemView::SelectRows);
////    ui->CountryInfor->setSelectionModel(QAbstractItemView::SingleSelection);
//    ui->CountryInfor->setShowGrid(false);
//    ui->CountryInfor->setAlternatingRowColors(true);
}

void MainWindow::createHubeiInfor(){
    ui->HubeiInfor->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置为进制用户编辑
    ui->HubeiInfor->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->HubeiInfor->setSelectionModel(QAbstractItemView::SingleSelection);
    ui->HubeiInfor->setShowGrid(false);
    ui->HubeiInfor->setAlternatingRowColors(true);
    ui->HubeiInfor->verticalHeader()->hide();
}

void MainWindow::createWuhanInfor(){
    ui->WuhanInfor->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置为进制用户编辑
    ui->WuhanInfor->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->WuhanInfor->setSelectionModel(QAbstractItemView::SingleSelection);
//    ui->WuhanInfor->setShowGrid(false);
    ui->WuhanInfor->setAlternatingRowColors(true);

}

//联系作者
void MainWindow::on_Autor_clicked()
{
    QMessageBox::information(this,QStringLiteral("联系作者"),QStringLiteral("邮箱:15385433870@163.com\n个人主页：https://blog.csdn.net/qq_41895747/article/details/104135166"));
}

//版本信息
void MainWindow::on_Version_clicked()
{
    QMessageBox::information(this,QStringLiteral("版本信息"),QStringLiteral("Version：1.1\n开发时间：2020.02.02"));
}

//退出程序
void MainWindow::on_Exit_clicked()
{
    this->close();
}
