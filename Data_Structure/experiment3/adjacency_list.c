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

//DFS遍历  连通图
void DFS(ALGraph *G,int v,int visited[]){
    printf("%d ",G->adjlist[v].data);   //输出取出的顶点
    visited[v]=1;       //输出后标记1
    ArcNode *p=G->adjlist[v].first;     //指向下一个节点
    while (p!=NULL){
        if (visited[p->adjvex]!=1)     //没被标记就继续递归
        {
            DFS(G,p->adjvex,visited);
        }
        p=p->next;      //被标记就继续找下一个邻接点
    }
}

//通用DFS遍历
void DFSTraverse(ALGraph *G,int v){
    int visited[7]={0};
    for (int i = 0; i < G->vexnum; i++)     //如果被标记就看下一个顶点
    {
        if (visited[i]!=1)          //找到连通分量
        {
            DFS(G,v,visited);       //对该连通分量DFS
        }
    }
    
}

//BFS遍历
void BFS(ALGraph *G,int v,int visited[]){
    //构建队列来处理邻接点
    int queue[100]={0};
    int front=0;
    int rear=0; //头尾指针
    //打印头顶点并入队
    printf("%d ",G->adjlist[v].data);
    visited[v]=1;
    queue[rear++]=v;
    //队非空就还有顶点没遍历
    while (front!=rear)
    {
        //出队然后找邻接点将邻接点入队
        int cur=queue[front++];
        ArcNode *p=G->adjlist[cur].first;   //拿到表头
        while (p!=NULL)
        {
            if (visited[p->adjvex]!=1)
            {
                printf("%d ",G->adjlist[p->adjvex].data);
                visited[p->adjvex]=1;
                queue[rear++]=p->adjvex;
            }
            p=p->next;
        }      
    }   
}

// BFS通用遍历
void BFSTraverse(ALGraph* G){
    int visited[7]={0};
    for (int i = 0; i < G->vexnum; i++)
    {
        if (visited[i]!=1)
        {
            BFS(G,i,visited);
        }
    }
}

int main()
{
    ALGraph *G=CreateALGraph();
    Traverse(G);
    DFSTraverse(G,0);
    printf("\n");
    BFSTraverse(G);
    return 0;
}