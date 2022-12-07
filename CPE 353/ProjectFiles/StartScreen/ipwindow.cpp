#include "ipwindow.h"
#include "ui_ipwindow.h"
#include <QLabel>
#include <QApplication>

IPWindow::IPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IPWindow)
{
    ui->setupUi(this);


    ui->label->setText("Enter IP Address"); //high score button
    ui->label->setStyleSheet("color: Black");
    ui->label->raise(); //makes it appear on top of everything else

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitSlot()));

}


IPWindow::~IPWindow()
{
    delete ui;
}

void IPWindow::exitSlot()
{
    IPWindow::close();
}


