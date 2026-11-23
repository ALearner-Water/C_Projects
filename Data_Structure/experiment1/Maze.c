#include <stdio.h>
#include <stdlib.h>

// 坐标点结构体
typedef struct
{
    int x, y;
} Point;

// 1. 链式队列节点
typedef struct QNode
{
    Point data;
    struct QNode *next;
} QNode;

// 链式队列
typedef struct
{
    QNode *front; // 队头
    QNode *rear;  // 队尾
} LinkQueue;

// 2. 链栈节点
typedef struct SNode
{
    Point data;
    struct SNode *next;
} SNode;

// 8x8迷宫：0是路，1是墙
int maze[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0}};

// 记录路径的前驱节点，方便回溯
Point parent[8][8];

// 四个移动方向：上下左右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 初始化队列
void initQueue(LinkQueue *q)
{
    q->front = q->rear = NULL;
}

// 入队
void enqueue(LinkQueue *q, Point p)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = p;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队
Point dequeue(LinkQueue *q)
{
    QNode *temp = q->front;
    Point p = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL; // 队列变空
    }
    free(temp);
    return p;
}

// 判断队列是否为空
int isEmpty(LinkQueue *q)
{
    return q->front == NULL;
}

// 入栈（头插法）
SNode *push(SNode *top, Point p)
{
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->data = p;
    newNode->next = top;
    return newNode;
}

// 打印迷宫
void printMaze()
{
    printf("迷宫地图 (0为通路, 1为墙壁):\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // 坐标为了直观，打印时+1
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// BFS 寻找最短路径
void findShortestPath()
{
    LinkQueue q;
    initQueue(&q);

    // 初始化 parent 数组，-1 表示未访问
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            parent[i][j].x = parent[i][j].y = -1;

    // 起点入队 (0, 0) 对应题目的 (1, 1)
    Point start = {0, 0};
    parent[0][0] = start; // 起点的父节点就是自己
    enqueue(&q, start);

    int found = 0;

    while (!isEmpty(&q))
    {
        Point cur = dequeue(&q);

        // 到达终点 (7, 7) 对应题目的 (8, 8)
        if (cur.x == 7 && cur.y == 7)
        {
            found = 1;
            break;
        }

        // 尝试往四个方向走
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 检查边界、是否是墙壁、是否未访问过
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 &&
                maze[nx][ny] == 0 && parent[nx][ny].x == -1)
            {

                // 记录前驱节点
                parent[nx][ny] = cur;
                Point next = {nx, ny};
                enqueue(&q, next);
            }
        }
    }

    // 处理结果
    if (!found)
    {
        printf("报错：没有找到从入口到出口的路径！\n");
        return;
    }

    // 使用链栈回溯路径
    SNode *stack = NULL;
    Point cur = {7, 7};

    // 从终点一路倒退回起点
    while (1)
    {
        stack = push(stack, cur);
        if (cur.x == 0 && cur.y == 0)
            break;                  // 回到起点了
        cur = parent[cur.x][cur.y]; // 找到它的前驱
    }

    // 出栈打印轨迹
    printf("最短路径的移动轨迹为 (对应题目坐标1~8):\n");
    int step = 1;
    while (stack != NULL)
    {
        SNode *temp = stack;
        // 打印时坐标 +1
        printf("第%d步: (%d, %d)\n", step++, stack->data.x + 1, stack->data.y + 1);
        stack = stack->next;
        free(temp);
    }
    printf("成功到达出口！\n");
}

int main()
{
    printMaze();
    findShortestPath();
    return 0;
}