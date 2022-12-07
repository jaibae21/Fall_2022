#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ipwindow.h"
#include "hscorewindow.h"


namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    IPWindow *newIPWindow;
    HScoreWindow *newScoreWindow;

public slots:
     void openIPWindow();
     void openHScoreWindow();


};
#endif // MAINWINDOW_H
