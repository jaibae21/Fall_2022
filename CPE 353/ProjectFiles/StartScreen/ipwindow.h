#ifndef IPWINDOW_H
#define IPWINDOW_H

#include <QMainWindow>

namespace Ui {
class IPWindow;
}

class IPWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IPWindow(QWidget *parent = nullptr);
    ~IPWindow();


private:
    Ui::IPWindow *ui;

private slots:
    void exitSlot();
};

#endif // IPWINDOW_H
