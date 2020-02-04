#ifndef CONNDLG_H
#define CONNDLG_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class ConnDlg;
}

class ConnDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnDlg(QWidget *parent = nullptr);
    ~ConnDlg();
    QString driverName() const;
    QString databaseName() const;
    QString userName() const;
    QString password() const;
    QString hostName() const;
    int port() const;//端口
    void createDB();//创建数据表
    void addsqliteConnect();//sqlite数据库连接
    QSqlError addConnection(const QString &driver,const QString &dbName,const QString &host,
                            const QString &user,const QString &passwd,int port = -1);

private slots:
    void on_cancelBtn_clicked();
    void on_connBtn_clicked();
    void driverChanged(const QString &);

private:
    Ui::ConnDlg *ui;
};

#endif // CONNDLG_H
