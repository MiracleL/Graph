
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hanshu.h"
#include <cctype>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    num = arg1;                //初始化动态的变量
    nod = new node[num]();
    graph = new Graphm(num);
    D = new int[num];
}



void MainWindow::on_add_pushButton_clicked()
{
    int val1=0,val2=0,k;
    QString city1=ui->city1->text(),city2=ui->city2->text(),dis=ui->distance->text();
    k=atoi(dis.toStdString().c_str());
    for(int i=0;i<graph->n();i++)
    {
        if(city1 == nod[i].str())
            val1=i;
        if(city2 == nod[i].str())
            val2=i;
    }
    graph->setEgde(val1,val2,k);
    ui->city1->clear();
    ui->city2->clear();
    ui->distance->clear();



}

void MainWindow::on_add_pushButton_2_clicked()
{
    if(ui->city->text()!="")
    {
        if(cout<num)
        {
            node k(ui->city->text(),cout);
            nod[cout] = k;
            cout++;
        }
        else
            qDebug() << "the number is full";
        ui->city->clear();
    }
    else
        qDebug() << "The widget is empty";


}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    for(int i=0;i<graph->n();i++)        //输出图的数组形式
    {
        QString ex="";
        if(i==0)
        {
            for(int k=0;k<graph->n();k++)
            {
                if(k==0)
                    ex+="     ";
                ex+=nod[k].str();
                ex+="   ";
            }
            ui->listWidget->addItem(ex);
        }
        for(int j=0;j<graph->n();j++)
        {
            if(j==0)
                ex=nod[i].str()+"   ";
            QString exp=QString::number(graph->weight(i,j));
            ex+=exp;
            ex+="   ";
        }
        ui->listWidget->addItem(ex);

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int val=-9;
    for(int i=0;i<graph->n();i++)
    {
        if(ui->lineInput->text()==nod[i].str())
        {
            val=nod[i].num();
            break;
        }
    }
    if(val>=0)
    {
        Dijkstra(graph,D,val);  //dijstra 算法一次只能操作一次节点查找路径，如果要多次操作，重新初始化
        add(graph);
        xiugai(graph,val,D);
        compa(graph);
        QString ex="     ";
        for(int j=0;j<graph->n();j++)
        {
            ex+=nod[j].str();
            ex+="  ";
        }
        ui->listWidget_2->addItem(ex);
        for(int j=0;j<graph->n();j++)
        {
            if(j==0)
                ex=ui->lineInput->text()+"   ";
            QString ex1=QString::number(D[j]);     //显示距离
            ex+=ex1;
            ex+="  ";
        }
        ui->listWidget_2->addItem(ex);
        for(int i=0; i<graph->n(); i++)
        {
            if(i!=val)                        //为了将自己到自己的路径剔除
                display(b[i]);
        }

        graph->MarkInit();
    }
    else
        qDebug() << "Input the right number";


}

void MainWindow::display(string a)
{
    QString ex="",val=" -> ";
    for(int j=0;j<a.size();j++)
    {
        for(int i=0;i<graph->n();i++)
        {
            if((a[j]-'0') == nod[i].num())
            {
                ex+=nod[i].str();
                if(j<a.size() -1)
                    ex+=val;
                break;
            }
        }

    }
    ui->listWidget_2->addItem(ex);
}
