#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGroupBox>
#include <QTableView>
#include <QListView>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createCountryInfor();//全国信息创建
    void createHubeiInfor();//湖北信息创建
    void createWuhanInfor();//武汉信息创建

private slots:
    void on_Autor_clicked();
    void on_Version_clicked();
    void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
