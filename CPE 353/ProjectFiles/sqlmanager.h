#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QDialog>
#include <QString>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class SQLManager;
}

class SQLManager : public QDialog
{
    Q_OBJECT

public:
    explicit SQLManager(QWidget *parent = nullptr);
    ~SQLManager();

    QString playername; //used to associate randomname to player

private:
    Ui::SQLManager *ui;

    QSqlQueryModel *model;
    QSqlDatabase db;

private slots:
    void populateName();
    void playerName();
};

#endif // SQLMANAGER_H
