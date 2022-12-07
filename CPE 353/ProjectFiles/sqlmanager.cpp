#include "sqlmanager.h"
#include "ui_sqlmanager.h"

SQLManager::SQLManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SQLManager)
{
    ui->setupUi(this);

    //reroll populates, ok confirms name, continue moves forward in the game
    connect(ui->rerollname, SIGNAL(clicked(bool)), this, SLOT(populateName()));
    connect(ui->okButton, SIGNAL(clicked(bool)), this, SLOT(playerName()));
    //set up and attempt to open database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("names.db");
    if(!db.open())
    {
        qDebug() << "Error: unable to open databse";
        return;
    }

    QSqlQuery q("DROP TABLE usernames");
    q.prepare("CREATE TABLE usernames ( name1 TEXT, name2 TEXT)");   //create table
//    //QSqlQuery q;
//    q.prepare("INSERT INTO usernames VALUES(:name1, :name2");  //prepare to populate it
//    q.bindValue(":name1", "tester");
//    q.bindValue(":name2", "walugi");
//    q.exec();
    //check table creation
    if(!q.exec())
    {
        qDebug() << "Error: unable to create table";
        return;
    }

     model = new QSqlQueryModel;
     model->setQuery("SELECT * FROM usernames");
     ui->tableView->setModel(model);


}

SQLManager::~SQLManager()
{
    delete ui;
}

void SQLManager::populateName()
{
    QSqlQuery q;
    q.prepare("INSERT INTO usernames (name1, name2)" "VALUES(:name1, :name2)");  //prepare to populate it
    q.bindValue(":name1", "tester");
    q.bindValue(":name2", "walugi");
    q.exec();
    model->setQuery("SELECT * FROM usernames");
    ui->tableView->setModel(model);
}

void SQLManager::playerName()
{
    QString name1;
    QString name2;

    name1 = ui->name1Edit->text();
    qDebug() << name1;
    name2 = ui->name2Edit->text();
    playername = name1 + name2;
    qDebug() << playername;

    ui->username->setText(playername);

}


