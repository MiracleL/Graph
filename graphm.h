#ifndef GRAPHM_H
#define GRAPHM_H

#include<iostream>
#include"global.h"

using namespace std;
class Graphm
{
private:
    int numVertex, numEdge; // numVertex 是顶点数量， numEdge是边的数量
    int **matrix;
    int *mark;
public:
    Graphm(int numVert)   //初始化操作，边到边的值都初始化为0
    {
        Init(numVert);
    }
    ~Graphm()
    {
        delete []mark;
        for(int i=0;i<numVertex;i++)
            delete []matrix[i];
        delete []matrix;
    }

    void Init(int n)
    {
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n];
        for(i=0; i<numVertex; i++)
            mark[i] = UNVISITED;
        matrix = (int **)new int* [numVertex];  //二级指针初始化
        for(i=0; i<numVertex; i++)
            matrix[i] = new int[numVertex];
        for(i=0; i<numVertex; i++)
            for(int j=0; j<numVertex; j++)
                matrix[i][j] = 0;

    }

    int n() { return numVertex; }
    int e() { return numEdge; }

    int first(int v)
    {
        for(int i=0; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    int next(int v, int w)     //寻找v1到v2的下一条边
    {
        for(int i=w+1; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    void setEgde(int v1, int v2, int wt)        //设置v1到v2的权值
    {
        if(wt < 0)
            cout << "Illegal value" << endl;
        else
        {
            if(matrix[v1][v2] == 0)
                numEdge++;
            matrix[v1][v2] = wt;
        }
    }

    void delEgde(int v1,int v2)         //删除v1到v2的边
    {
        if(matrix[v1][v2] != 0)
            numEdge--;
        matrix[v1][v2] = 0;
    }

    bool isEdge(int i, int j)
    {
        return matrix[i][j] != 0;
    }

    int weight(int v1, int v2)
    {
        return matrix[v1][v2];
    }

    int getMark(int v)
    {
        return mark[v];
    }

    void setMark(int v, int val)
    {
        mark[v] = val;
    }

    void MarkInit()
    {
        for(int i=0; i<numVertex; i++)
            mark[i] = UNVISITED;
    }
};

#endif // GRAPHM_H

