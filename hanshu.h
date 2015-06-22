#ifndef HANSHU_H
#define HANSHU_H
#include"graphm.h"
#include"string.h"
#include"strstream"
#include"global.h"
#include "qdebug.h"

int minVertex(Graphm *G,int *D)    //返回图G中最小的点
{
    int i, v=-1;
    for(i = 0; i<G->n(); i++)
        if(G->getMark(i) == UNVISITED){ v=i; break;}  //找出图G中没有被访问的点
    for(i++; i<G->n(); i++)
        if((G->getMark(i) == UNVISITED) && (D[i]<D[v]))
            v = i;
    return v;
}

void Dijkstra(Graphm *G,int *D, int s)
{

    int i,v,w;
    for(i=0; i<G->n(); i++)      //数组D初始化
    {
        if(i != s)
            D[i] = INFINITY;
        else
            D[i] = 0;
    }
    for(int i=0;i<G->n();i++)
        b[i]="";
    for(i=0; i<G->n(); i++)
    {
        v = minVertex(G,D);
        if(D[v] == INFINITY)      //为了让开始的节点为s，这一步很重要
            return;
        G->setMark(v, VISTED);
        for(w=G->first(v); w<G->n(); w = G->next(v,w))   //很巧妙
        {
            strstream val;
            string val1;
            if(D[w] > D[v] + G->weight(v, w))
            {
                D[w] = D[v] + G->weight(v, w);
                val << v;
                val >> val1;
                b[w]+=val1;                  //只有D[]路径被修改了，表明这个节点
            }

        }

    }
    for(int j=0;j<G->n();j++)
    {
        strstream val;
        string val1;
        val << j;
        val >> val1;
        b[j]+=val1;
    }

}
void inserts(int i,string va,int k)    //递归实现修改路径的值，很巧妙
{
    int val=va[0]-'0';
    if(val != k)
    {
        inserts(val,b[val],k);
        b[i].insert(0,b[val]);
    }
    else
        return;
}

void xiugai(Graphm *G,int k,int *D)
{
    for(int i=0;i<G->n();i++)
    {
        if(D[i] != INFINITY)
            inserts(i,b[i],k);
    }
}
void add(Graphm *G)           //非常重要
{
    for(int j=0;j<G->n();j++)
    {
        char a=j+'0';
        b[j]+=a;
    }
}


void compa(Graphm *G)
{
    for(int j=0;j<G->n();j++)
    {
        for(int i=0;i<b[j].size()-1;i++)
        {
            if(b[j][i] == b[j][i+1])
            {
                b[j].erase(i+1,i+2);
            }
        }
    }
}
#endif // HANSHU_H
/*
strstream val;
string val1;
val << j;

val >> val1;
b[j]+=val1;  */
