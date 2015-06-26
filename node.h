#ifndef NODE_H
#define NODE_H
#include"QString"
class node
{
private:
    QString s;
    int number;

public:
    node(){}
    node(QString x,int n)
    {
        s = x;
        number = n;
    }
    QString str(){ return s;}
    int num(){ return number;}



};

#endif // NODE_H

