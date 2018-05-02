#ifndef FISH_H
#define FISH_H
#include "QDebug"
#include "QTimer"
#include <QMainWindow>

namespace Ui {
class fish;
}


class fish : public QMainWindow
{
    Q_OBJECT

public:
    explicit fish(QWidget *parent = 0);
    ~fish();

   void delay(int t);
public slots:
    void myslot();
    void open();
    void close();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fish *ui;
    QTimer *timer;
};



#endif // FISH_H
