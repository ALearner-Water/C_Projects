#include <stdio.h>
#include <stdlib.h>
#define MaxINT 0x3f3f3f3f // 无穷远
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

//DFS 连通图
void DFS(AMGraph* G,int v,int visited[]){
    printf("%d ",G->vexs[v]);   //输出顶点
    visited[v]=1;           //输出后标记为1
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->arcs[v][i]!=MaxINT&&visited[i]!=1)   //没被标记且有边
        {
            DFS(G,i,visited);
        }
    }
}

//DFS通用遍历
void DFSTraverse(AMGraph *G,int v){
    int visited[7]={0};
    for (int i = 0; i < G->vexnum; i++)
    {
        if (visited[i]!=1)
        {
            DFS(G,v,visited);
        }     
    }
}

//BFS遍历
void BFS(AMGraph* G,int v,int visited[]){
    //用队列装邻接点
    int queue[100]={0};
    int front=0;
    int rear=0;
    printf("%d ",G->vexs[v]);
    visited[v]=1;
    queue[rear++]=v;
    //队不为空就还有点
    while (front!=rear)
    {
        int cur=queue[front++]; //出队找邻接点
        for (int i = 0; i < G->vexnum; i++)
        {
            if (G->arcs[cur][i]!=MaxINT&&visited[i]!=1)
            {
                printf("%d ",G->vexs[i]);   //输出
                visited[i]=1;
                queue[rear++]=i;   //入队
            }
        }
        
    }
    
}
//BFS通用遍历
void BFSTraverse(AMGraph* G){
    int visited[7]={0};
    for (int i = 0; i < G->vexnum; i++)
    {
        if (visited[i]!=1)
        {
        BFS(G,i,visited);
        }
    }
}

//获得数组下标
int Locate(AMGraph *G,VType v){
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->vexs[i]==v)
        {
            return i;
        }
    }
    return -1;
}
//Prim算法
void Prim(AMGraph *G,VType v0){
    int sum =0; //定义总权
    // 创建辅助数组
    struct
    {
        VType v;     // 顶点
        int lowcast; // 到树的最短距离 =0代表已经纳入树
    } closedge[100]; // 该点到树的距离

    // 定位顶点并做初始化
    int point=Locate(G,v0);
    for (int i = 0; i < G->vexnum; i++)
    {
        closedge[i].v=v0;   //每个点到集合的最短点
        closedge[i].lowcast=G->arcs[point][i];  //两点之间的距离
    }
    //顶点加入集合
    closedge[point].lowcast=0;
    //开始不断找点 循环n-1次
    for (int j = 1; j < G->vexnum ; j++)
    {
        int min =MaxINT;
        int min_point=-1;   //最小值下标
        //循环找最小lowcast
        for (int k = 0; k < G->vexnum; k++)
        {
            if (closedge[k].lowcast!=0&&closedge[k].lowcast<min)
            {
                min=closedge[k].lowcast;
                min_point=k;
            }
        }
        //找到后将该点加入集合
        closedge[min_point].lowcast=0;
        sum+=min;
        printf("%d -- %d  %d\n",closedge[min_point].v,G->vexs[min_point],min);
        // 更新closedge数组
        for (int w = 0; w < G->vexnum; w++)
        {
            if (closedge[w].lowcast != 0)
            {
                if (closedge[w].lowcast > G->arcs[min_point][w])
                {
                    closedge[w].lowcast=G->arcs[min_point][w];
                    closedge[w].v=G->vexs[min_point];
                }
            }
        }
    }
    printf("总权值为%d",sum);
}

int main()
{
    AMGraph *G=CreateAMGraph();
    Traverse(G);
    int visited_DFS[7]={0};
    DFS(G,0,visited_DFS);
    printf("\n");
    int visited_BFS[7]={0};
    BFS(G,0,visited_BFS);
    printf("\n");
    BFSTraverse(G);
    printf("\n");
    Prim(G,0);
    return 0;
}
