#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QApplication>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QMainWindow::showFullScreen();



    /*QPixmap background(":/images/Forest1.png");
    background = background.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);*/

    ui->StartButton->setFlat(true); //to make background on button transparent
    ui->StartButton->setText("Start Game"); //start game  button
    ui->StartButton->setStyleSheet("color: #FFFFFF");
    ui->StartButton->raise(); //makes it appear on top of everything else

    ui->HighScore->setFlat(true); //to make background on button transparent
    ui->HighScore->setText("High Scores"); //high score button
    ui->HighScore->setStyleSheet("color: #FFFFFF");
    ui->HighScore->raise(); //makes it appear on top of everything else


    QPixmap background_image(":/images/Forest1.png"); //backgroung image
    ui->label->setPixmap(background_image);
    ui->label->setScaledContents(true);
    ui->label->showFullScreen();

    //makes the start button open a new window for IP addresses
    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(openIPWindow()));

    //makes the high score button open a new window for user to view scores
    connect(ui->HighScore, SIGNAL(clicked()), this, SLOT(openHScoreWindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openIPWindow()
{
    newIPWindow = new IPWindow;
    newIPWindow->show();
}

void MainWindow::openHScoreWindow()
{
    newScoreWindow = new HScoreWindow;
    newScoreWindow->show();
}

