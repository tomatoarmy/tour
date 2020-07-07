#include <stdio.h>
#include <stdlib.h>

#define Max 50
#define Max_Length 5000

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

void Init_Graph(Graph &g);
void Short_Path(int num, Graph &g, int de);
void footprint(int path[], int p, Graph g);
void description(Graph g);
void printMenue();

int main()
{
    Graph g;
    Init_Graph(g);
    int choice;
    int num;
    int de;
    while(1)
    {
    printf( "\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n" );
	printf( "\t\t\t\t\t\t┃  安徽师范大学校园导游系统 ┃\n" );
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━┳━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃1、校园导游               ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃2、景点介绍               ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃3、退出                   ┃\n"); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf("\t\t\t\t\t\t请输入要执行的操作:\n");
    printf("\t\t\t\t\t\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printMenue();
        printf("\t\t\t\t\t\t请输入当前位置：\n");
        printf("\t\t\t\t\t\t");
        scanf("%d", &num);
        printf("\t\t\t\t\t\t请输入需要到达的位置：\n");
        printf("\t\t\t\t\t\t");
        scanf("%d", &de);
        printf("\t\t\t\t\t\t------------------\n");
        Short_Path(num, g, de);
        printf("\n");
        break;
    case 2:
        description(g);
        printf("\n");
        break;
    case 3:
        exit(-1);
    default:
        exit(-1);
        break;
    }
    }
    return 0;
}

void Init_Graph(Graph &g)
{
    
    g.nodenum = 26;
    g.arcnum = 57;
    //图中边的数量对问题结果没有实质性影响，这里不做考虑
    /*为点之间的距离赋值*/
    for(int i =0; i < 26; i++)//首先将所有点之间的距离赋为最大值
    {
        for (int j = 0; j < 26; j++)
        {
            g.arc[i][j].length = Max_Length;
        }
        
    }
    g.arc[0][1].length = g.arc[1][0].length = 100;
    g.arc[0][2].length = g.arc[2][0].length = 150;
    g.arc[0][3].length = g.arc[3][0].length = 500;
    g.arc[0][4].length = g.arc[4][0].length = 450;
    g.arc[1][2].length = g.arc[2][1].length = 50;
    g.arc[1][3].length = g.arc[3][1].length = 200;
    g.arc[1][4].length = g.arc[4][1].length = 400;
    g.arc[2][3].length = g.arc[3][2].length = 350;
    g.arc[2][4].length = g.arc[4][2].length = 550;
    g.arc[3][4].length = g.arc[4][3].length = 400;
    g.arc[3][5].length = g.arc[5][3].length = 300;
    g.arc[3][6].length = g.arc[6][3].length = 400;
    g.arc[4][5].length = g.arc[5][4].length = 50;
    g.arc[4][8].length = g.arc[8][4].length = 100;
    g.arc[4][9].length = g.arc[9][4].length = 200;
    g.arc[4][10].length = g.arc[10][4].length = 300;
    g.arc[5][6].length = g.arc[6][5].length = 150;
    g.arc[5][7].length = g.arc[7][5].length = 50;
    g.arc[6][7].length = g.arc[7][6].length = 50;
    g.arc[6][15].length = g.arc[15][6].length = 100;
    g.arc[7][8].length = g.arc[8][7].length = 50;
    g.arc[7][15].length = g.arc[15][7].length = 150;
    g.arc[7][14].length = g.arc[14][7].length = 200;
    g.arc[7][17].length = g.arc[17][7].length = 300;
    g.arc[8][14].length = g.arc[14][8].length = 250;
    g.arc[8][12].length = g.arc[12][8].length = 170;
    g.arc[9][12].length = g.arc[12][9].length = 100;
    g.arc[9][10].length = g.arc[10][9].length = 150;
    g.arc[10][11].length = g.arc[11][10].length = 200;
    g.arc[10][12].length = g.arc[12][10].length = 300;
    g.arc[10][13].length = g.arc[13][10].length = 220;
    g.arc[11][12].length = g.arc[12][11].length = 300;
    g.arc[11][13].length = g.arc[13][11].length = 150;
    g.arc[12][13].length = g.arc[13][12].length = 250;
    g.arc[12][14].length = g.arc[14][12].length = 150;
    g.arc[12][18].length = g.arc[18][12].length = 200;
    g.arc[12][19].length = g.arc[19][12].length = 230;
    g.arc[12][24].length = g.arc[24][12].length = 420;
    g.arc[13][19].length = g.arc[19][13].length = 60;
    g.arc[14][15].length = g.arc[15][14].length = 200;
    g.arc[14][17].length = g.arc[17][14].length = 150;
    g.arc[14][18].length = g.arc[18][14].length = 50;
    g.arc[15][16].length = g.arc[16][15].length = 200;
    g.arc[15][17].length = g.arc[17][15].length = 150;
    g.arc[15][25].length = g.arc[25][15].length = 50;
    g.arc[16][17].length = g.arc[17][16].length = 60;
    g.arc[16][21].length = g.arc[21][16].length = 200;
    g.arc[17][18].length = g.arc[18][17].length = 60;
    g.arc[17][22].length = g.arc[22][17].length = 200;
    g.arc[18][19].length = g.arc[19][18].length = 300;
    g.arc[18][23].length = g.arc[23][18].length = 200;
    g.arc[18][24].length = g.arc[24][18].length = 250;
    g.arc[19][24].length = g.arc[24][19].length = 300;
    g.arc[20][21].length = g.arc[21][20].length = 20;
    g.arc[21][22].length = g.arc[22][21].length = 50;
    g.arc[22][23].length = g.arc[23][22].length = 50;
    g.arc[23][24].length = g.arc[24][23].length = 30;
    for(int i = 0; i < 26; i++)
        g.arc[i][i].length = 0;
    
    /*每个点的信息*/
    g.nodelist[0].order = 0;
    g.nodelist[0].name = (char*)"北门";
    g.nodelist[0].info = (char*)"安徽师范大学的北面入口，五大入口之一，对面中央城";

    g.nodelist[1].order = 1;
    g.nodelist[1].name = (char*)"小区";
    g.nodelist[1].info = (char*)"安徽师范大学内附属小区，校内小区";

    g.nodelist[2].order = 2;
    g.nodelist[2].name = (char*)"北体";
    g.nodelist[2].info = (char*)"安徽师范大学北体育馆，体育生专用体育场，举办运动会的场所";

    g.nodelist[3].order = 3;
    g.nodelist[3].name = (char*)"西北门";
    g.nodelist[3].info = (char*)"安徽师范大学西北侧入口，五大入口之一";

    g.nodelist[4].order = 4;
    g.nodelist[4].name = (char*)"北圆盘";
    g.nodelist[4].info = (char*)"安徽师范大学北门圆盘，连接外国语学院，研究生宿舍和小食代";

    g.nodelist[5].order = 5;
    g.nodelist[5].name = (char*)"研舍";
    g.nodelist[5].info = (char*)"安徽师范大学研究生宿舍，安师大内配置最好的学生宿舍";

    g.nodelist[6].order = 6;
    g.nodelist[6].name = (char*)"一食堂";
    g.nodelist[6].info = (char*)"安徽师范大学第一食堂，安师大三大食堂之一";

    g.nodelist[7].order = 7;
    g.nodelist[7].name = (char*)"秋实园";
    g.nodelist[7].info = (char*)"安徽师范大学秋实园学生宿舍，学生宿舍相对较为陈旧，有4人间和六人间";

    g.nodelist[8].order = 8;
    g.nodelist[8].name = (char*)"小食代";
    g.nodelist[8].info =(char*) "安徽师范大学小食代美食广场，其中包含安师大的一个食堂，以及采购的超市和各种商店";

    g.nodelist[9].order = 9;
    g.nodelist[9].name = (char*)"外语";
    g.nodelist[9].info = (char*)"安徽师范大学外国语学院，不同于其他学院，有自己专用的教学楼";

    g.nodelist[10].order = 10;
    g.nodelist[10].name = (char*)"地旅学院";
    g.nodelist[10].info = (char*)"安徽师范大学地理与旅游学院，学院楼设计十分美观";

    g.nodelist[11].order = 11;
    g.nodelist[11].name = (char*)"东门";
    g.nodelist[11].info = (char*)"安徽师范大学东侧入口，五大入口之一，是师大的主大门";

    g.nodelist[12].order = 12;
    g.nodelist[12].name = (char*)"图书馆";
    g.nodelist[12].info = (char*)"安徽师范大学敬文图书馆，安师大的代表性建筑之一";

    g.nodelist[13].order = 13;
    g.nodelist[13].name = (char*)"化材";
    g.nodelist[13].info = (char*)"安徽师范大学化学与材料学院，安师大最大的学院之一也是师大最强的学院之一";

    g.nodelist[14].order = 14;
    g.nodelist[14].name = (char*)"教学区2";
    g.nodelist[14].info = (char*)"安徽师范大学学生专用教学用楼区2，有着相连的多个教学楼";

    g.nodelist[15].order = 15;
    g.nodelist[15].name = (char*)"礼堂";
    g.nodelist[15].info = (char*)"安徽师范大学大礼堂，举办一些重大活动专用";

    g.nodelist[16].order = 16;
    g.nodelist[16].name = (char*)"二食堂";
    g.nodelist[16].info = (char*)"安徽师范大学二食堂，安师大三大食堂之一，拥有较高的人气";

    g.nodelist[17].order = 17;
    g.nodelist[17].name = (char*)"夏沁园";
    g.nodelist[17].info = (char*)"安徽师范大学夏沁园学生宿舍，宿舍相对较新，基本都是4人间";

    g.nodelist[18].order = 18;
    g.nodelist[18].name = (char*)"教学区1";
    g.nodelist[18].info = (char*)"安徽师范大学教学楼区1，是师大最大的一个教学楼1号楼";

    g.nodelist[19].order = 19;
    g.nodelist[19].name = (char*)"计信学院";
    g.nodelist[19].info = (char*)"安徽师范大学计算机与信息学院，是师大最新的学院";

    g.nodelist[20].order = 20;
    g.nodelist[20].name =(char*) "西南门";
    g.nodelist[20].info = (char*)"安徽师范大学西南门，五大入口之一";

    g.nodelist[21].order = 21;
    g.nodelist[21].name = (char*)"校医";
    g.nodelist[21].info = (char*)"安徽师范大学校医院，西南门旁";

    g.nodelist[22].order = 22;
    g.nodelist[22].name = (char*)"篮球场";
    g.nodelist[22].info = (char*)"安徽师范大学篮球场，位于南体育场旁边，举办校篮球赛场所";

    g.nodelist[23].order = 23;
    g.nodelist[23].name =(char*) "体育馆";
    g.nodelist[23].info = (char*)"安徽师范大学南体育馆，非体育专业学生专用";

    g.nodelist[24].order = 24;
    g.nodelist[24].name = (char*)"足球场";
    g.nodelist[24].info =(char*) "安徽师范大学足球场，篮球场旁边，经常有足球比赛";

    g.nodelist[25].order = 25;
    g.nodelist[25].name = (char*)"西门";
    g.nodelist[25].info = (char*)"安徽师范大学西侧入口，五大入口之一，对面德胜广场";
    
}

void Short_Path(int num, Graph &g, int de)
{
    int len = g.nodenum;
    int is_tra[len];
    int dis[len];
    int path[len];
    for(int i = 0; i < len; i++)
    {
        is_tra[i] = 0;
        path[i] = -1;
    }

    for(int i = 0; i < len; i++)
    {
        dis[i] = g.arc[num][i].length;
    }

    is_tra[num] = 1;

    for(int i = 0; i < len; i++)
    {
        int temp = Max_Length + 1;
        int flag = -1;
        for( int w = 0; w < len; w++)  //找出未被确定且距离出发点最近的点
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
       
        is_tra[flag] = 1;
        for( int w = 0; w < len; w++)
        {
            if(is_tra[w] == 0 && (temp + g.arc[flag][w].length < dis[w]))
            {
                dis[w] = temp + g.arc[flag][w].length;
                path[w] = flag;
            }
        }
    }

    printf("\t\t\t\t\t\t最短路径为：\n");
    printf("\t\t\t\t\t\t%s->", g.nodelist[num].name);
    footprint(path, de, g);
    printf("%s\n", g.nodelist[de].name);
    printf("\t\t\t\t\t\t最短路径的总长度为：\n");
    printf("\t\t\t\t\t\t%dm\n", dis[de]);
    
    
}

void footprint(int path[], int p, Graph g)
{
    int d = path[p];
    if(d != -1)
    {
        footprint(path, d, g);
        printf("%s->", g.nodelist[path[p]].name);
    }
}

void description(Graph g)
{
    int num;
    printMenue();
    printf("\t\t\t\t\t\t请选择景点序号：\n");
    printf("\t\t\t\t\t\t");
    scanf("%d", &num);
    printf("\t\t\t\t\t\t%s\n", g.nodelist[num].info);
}

void printMenue()
{
	printf( "\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n" );
	printf( "\t\t\t\t\t\t┃             安徽师范大学景点一览表           ┃\n" );
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━┳━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃0.学校北门              ┃1.小区              ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃2.北体育馆              ┃3.西北门            ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃4.北圆盘                ┃5.研究生宿舍        ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃6.一食堂                ┃6.秋实园            ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃8.小食代                ┃9.外语学院          ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃10.地旅学院             ┃11.东大门           ┃\n" ); 
	printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
	printf( "\t\t\t\t\t\t┃12.图书馆               ┃13.化材学院         ┃\n" ); 
    printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf( "\t\t\t\t\t\t┃14.教学区2              ┃15.礼堂             ┃\n" ); 
    printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf( "\t\t\t\t\t\t┃16.二食堂               ┃17.夏沁园           ┃\n" ); 
    printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf( "\t\t\t\t\t\t┃18.教学区1              ┃19.计信学院         ┃\n" ); 
    printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf( "\t\t\t\t\t\t┃20.西南门               ┃21.校医院           ┃\n" ); 
    printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf( "\t\t\t\t\t\t┃22.篮球场               ┃23.体育馆           ┃\n" ); 
    printf( "\t\t\t\t\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n" ); 
    printf( "\t\t\t\t\t\t┃24.足球场               ┃25.西大门           ┃\n" ); 
	printf( "\t\t\t\t\t\t┗━━━━━━━━━━━━┻━━━━━━━━━━━━┛\n" );
}

