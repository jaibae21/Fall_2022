#ifndef HSCOREWINDOW_H
#define HSCOREWINDOW_H

#include <QMainWindow>

namespace Ui {
class HScoreWindow;
}

class HScoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HScoreWindow(QWidget *parent = nullptr);
    ~HScoreWindow();

private:
    Ui::HScoreWindow *ui;
private slots:
    void exitSlot();
};

#endif // HSCOREWINDOW_H
