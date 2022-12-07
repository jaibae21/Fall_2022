#include "hscorewindow.h"
#include "ui_hscorewindow.h"

HScoreWindow::HScoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HScoreWindow)
{
    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitSlot()));
}

HScoreWindow::~HScoreWindow()
{
    delete ui;
}

void HScoreWindow::exitSlot()
{
    HScoreWindow::close();
}

