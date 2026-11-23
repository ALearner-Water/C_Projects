#include <stdio.h>
#include <stdlib.h>
#define MaxINT 32767    //无穷远
typedef int VType;  //顶点数据类型

//邻接矩阵
typedef struct AMGraph
{
    VType vexs[100];    //顶点表
    int arcs[100][100];  //邻接矩阵
    int vexnum;  //顶点数和边数
    int arcnum;
}AMGraph;

//构造邻接矩阵
AMGraph* CreateAMGraph(){
    AMGraph *G=(AMGraph*)malloc(sizeof(AMGraph));
    //创建之后需要初始化
    G->vexnum=7;
    G->arcnum=9;
    //初始化顶点表
    for (int i = 0; i < G->vexnum; i++)
    {
        G->vexs[i]=i;
    }
    //初始化邻接矩阵
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < (G->vexnum); j++)
        {
            G->arcs[i][j] = MaxINT;
        }
        G->arcs[i][i] = 0;
    }
    // 填入边
    G->arcs[0][1] = 28;
    G->arcs[1][0] = 28;
    G->arcs[0][5] = 10;
    G->arcs[5][0] = 10;

    G->arcs[1][2] = 16;
    G->arcs[2][1] = 16;
    G->arcs[1][6] = 14;
    G->arcs[6][1] = 14;

    G->arcs[2][3] = 12;
    G->arcs[3][2] = 12;

    G->arcs[3][4] = 22;
    G->arcs[4][3] = 22;
    G->arcs[3][6] = 18;
    G->arcs[6][3] = 18;

    G->arcs[4][5] = 25;
    G->arcs[5][4] = 25;
    G->arcs[4][6] = 24;
    G->arcs[6][4] = 24;
    return G;
}

void Traverse(AMGraph *G)
{
    // 打印表头，先空一格对齐
    printf("\t");
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%d\t", G->vexs[i]);
    }
    printf("\n");

    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%d\t", G->vexs[i]);
        for (int j = 0; j < G->vexnum; j++)
        {
            if (G->arcs[i][j]==MaxINT)
            {
                printf("MAX\t");
            }
            else{
            printf("%d\t", G->arcs[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    AMGraph *G=CreateAMGraph();
    Traverse(G);
    return 0;
}
