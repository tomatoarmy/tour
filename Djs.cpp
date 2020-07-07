#include <stdio.h>
#include <limits.h>

#define Max 500
typedef struct arcNode  //存储一条边的信息
{
    int length;
}arcNode;


typedef struct Node  //存储一个节点的信息
{
    int order;
    char *name;
    char *info;
}Node;

typedef struct Graph
{
    int nodenum;//点的数量
    int arcnum;//边的数量
    arcNode arc[Max][Max];
    Node nodelist[Max];
}Graph;


void Init_Graph(Graph &g)
{
    g.nodenum = 6;
    g.arcnum = 8;
    g.arc[0][0].length = 0;
    g.arc[0][1].length = g.arc[1][0].length = Max-1;
    g.arc[0][2].length = g.arc[2][0].length = 10;
    g.arc[0][3].length = g.arc[3][0].length = Max-1;
    g.arc[0][4].length = g.arc[4][0].length = 30;
    g.arc[0][5].length = g.arc[5][0].length = 100;
    g.arc[1][1].length = 0;
    g.arc[1][2].length = g.arc[2][1].length = 5;
    g.arc[1][3].length = g.arc[3][1].length = Max-1;
    g.arc[1][4].length = g.arc[4][1].length = Max-1;
    g.arc[1][5].length = g.arc[5][1].length = Max-1;
    g.arc[2][2].length = 0;
    g.arc[2][3].length = g.arc[3][2].length = 50;
    g.arc[2][4].length = g.arc[4][2].length = Max-1;
    g.arc[2][5].length = g.arc[5][2].length = Max-1;
    g.arc[3][3].length = 0;
    g.arc[3][4].length = g.arc[4][3].length = 20;
    g.arc[3][5].length = g.arc[5][3].length = 10;
    g.arc[4][4].length = 0;
    g.arc[4][5].length = g.arc[5][4].length = 60;
    g.arc[5][5].length = 0;
    for(int i = 0; i < 6; i++)
    {
        g.nodelist[i].order = i;
    }

}


int main()
{

    int dis[6];//记录距离
    int is_tra[6];//记录当前路径长度是否是最短路径
    int i,j,w;
    Graph g;
    Init_Graph(g);
    for(i = 0; i <6; i++)
    {
        is_tra[i] = 0;
    }
    for(i = 0;i < 6;i++)
    {
        dis[i] = g.arc[0][i].length;
    }
    is_tra[0] = 1;

    for(i = 0;i < 6; i++)
    {
        int temp = Max;
        int flag = -1;
        for( w = 0; w < 6; w++)  //找出未被确定且距离出发点最近的点
        {
            if(is_tra[w] == 0)
            {
                if(dis[w] < temp)
                {
                    flag = w;
                    temp = dis[w];
                }
            }
        }
        if(flag != -1)
        {
        is_tra[flag] = 1;
        for( w = 0; w < 6; w++)
        {
            if(is_tra[w] == 0 && (temp + g.arc[flag][w].length < dis[w]))
            {
                dis[w] = temp + g.arc[flag][w].length;
            }
        }
        }
    }

    for(i = 0; i < 6; i++)
        printf("%d\n", dis[i]);

    return 0;
}