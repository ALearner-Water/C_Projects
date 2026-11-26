//邻接矩阵
#include <stdio.h>
#include <stdlib.h>
#define MAXINT 32767
typedef int Vtype;
//定义
typedef struct AMGraph
{
    Vtype vex[100];
    int arcs[100][100];
    int arcnum;
    int vexnum;
}AMGraph;

AMGraph* Create(){
    AMGraph *G=(AMGraph*)malloc(sizeof(AMGraph));
    G->vexnum=7;
    G->arcnum=9;
    for (int i = 0; i < G->vexnum; i++)
    {
        G->vex[i]=i;
    }
    
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++)
        {
            if (i!=j)
            {
                G->arcs[i][j] = MAXINT;
            }else{
                G->arcs[i][j]=0;
            }
        }
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

int LOCATE(AMGraph *G,Vtype v0){
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->vex[i]==v0)
        {
            return i;
        }
    }
    return -1;
}

void Prim(AMGraph *G,Vtype v0){
    int sum=0;
    int point=LOCATE(G,v0);
    struct 
    {
        Vtype v;
        int lowcost;
    }closegde[100];
    for (int i = 0; i < G->vexnum; i++)
    {
        closegde[i].v=v0;
        closegde[i].lowcost=G->arcs[point][i];
    }
    closegde[point].lowcost=0;
    for (int i = 1; i < G->vexnum; i++)
    {
        int min=MAXINT;
        int minpoint=-1;
        for ( int j = 0; j < G->vexnum; j++)
        {
            if (closegde[j].lowcost!=0&&closegde[j].lowcost<min)
            {
                min=closegde[j].lowcost;
                minpoint=j;
            }
        }
        sum+=min;
        printf("%d -- %d %d\n",closegde[minpoint].v,G->vex[minpoint],min);
        closegde[minpoint].lowcost=0;
        for (int k = 0; k < G->vexnum; k++)
        {
            if (closegde[k].lowcost!=0&&closegde[k].lowcost>G->arcs[minpoint][k])
            {
                closegde[k].lowcost=G->arcs[minpoint][k];
                closegde[k].v=G->vex[minpoint];
            }
        }
    }
    printf("sum=%d",sum);
}

void travsrse(AMGraph *G){
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("\t%d",G->vex[i]);
    }
    printf("\n");
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%d\t",i);
        for (int j = 0; j < G->vexnum; j++)
        {
            if (G->arcs[i][j]==MAXINT)
            {
                printf("MAX\t");
            }
            else{
            printf("%d\t",G->arcs[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    AMGraph *G=Create();
    travsrse(G);
    Prim(G,0);
    return 0;
}
