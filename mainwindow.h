#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdebug.h"
#include <QMainWindow>
#include "graphm.h"
#include "node.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int num,cout=0;
    Graphm *graph;
    node *nod;
    int *D;
    void display(string a);

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_add_pushButton_clicked();

    void on_add_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
