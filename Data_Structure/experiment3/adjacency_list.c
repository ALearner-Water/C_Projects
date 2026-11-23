#include <stdio.h>
#include <stdlib.h>
typedef int VType; // 顶点数据类型
// 邻接表
// 边节点
typedef struct ArcNode
{
    int adjvex;           // 邻接点位置
    int weigth;           // 一条边的权值
    struct ArcNode *next; // 下一个边节点
} ArcNode;

// 头节点
typedef struct VNode
{
    VType data;
    ArcNode *first;
} VNode, AdjList[100]; // 多条链表组成的数组

// 邻接表结构体
typedef struct ALGraph
{
    AdjList adjlist;
    int vexnum;
    int arcnum;
} ALGraph;

// 使用头插法插入节点
void addArc(ALGraph *G, int v, int adv, int w)
{ // 顶点，邻接点，权
    ArcNode *node = (ArcNode *)malloc(sizeof(ArcNode));
    node->adjvex = adv;
    node->weigth = w;
    // 使用头插法插入
    node->next = G->adjlist[v].first;
    G->adjlist[v].first = node;
}

// 构造邻接表
ALGraph *CreateALGraph()
{
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph));
    // 初始化顶点和边
    G->vexnum = 7;
    G->arcnum = 9;
    for (int i = 0; i < G->vexnum; i++)
    {
        G->adjlist[i].data = i;        // 顶点的值就是编号i
        G->adjlist[i].first = NULL; // 一开始，每个顶点还没有边，链表为空
    }
    // 添加边
    addArc(G, 0, 1, 28);
    addArc(G, 1, 0, 28);
    addArc(G, 0, 5, 10);
    addArc(G, 5, 0, 10);
    addArc(G, 1, 2, 16);
    addArc(G, 2, 1, 16);
    addArc(G, 1, 6, 14);
    addArc(G, 6, 1, 14);
    addArc(G, 2, 3, 12);
    addArc(G, 3, 2, 12);
    addArc(G, 3, 4, 22);
    addArc(G, 4, 3, 22);
    addArc(G, 3, 6, 18);
    addArc(G, 6, 3, 18);
    addArc(G, 4, 5, 25);
    addArc(G, 5, 4, 25);
    addArc(G, 4, 6, 24);
    addArc(G, 6, 4, 24);
    return G;
}
//遍历输出
void Traverse(ALGraph *G){
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("顶点%d：", G->adjlist[i].data);
        ArcNode *p = G->adjlist[i].first; // p指向当前顶点的边链表头
        while (p != NULL)
        {
            printf("%d(%d) ", p->adjvex, p->weigth);
            p = p->next; // 指针向后移动，关键！
        }
        printf("\n");
    }
}

int main(){
    ALGraph *G=CreateALGraph();
    Traverse(G);
    return 0;
}