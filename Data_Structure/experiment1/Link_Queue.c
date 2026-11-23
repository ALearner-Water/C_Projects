#include <stdio.h>
#include <stdlib.h>
typedef int ElType;

// 定义队列节点
typedef struct queue
{
    struct queue *next;
    ElType data;
} QNode;

// 再定义头尾指针 这是队列结构
typedef struct link_q
{
    QNode *front;
    QNode *rear;
} QLink;

//做初始化 带头结点
QLink* init(){
    QLink *Q=(QLink*)malloc(sizeof(QLink));
    QNode *node=(QNode*)malloc(sizeof(QNode));
    node->next=NULL;
    Q->front=Q->rear=node;  //头尾都指向头节点
    return Q;
}

//入队操作 尾插法
void InQueue(QLink *Q,ElType e){
    //创建新节点
    QNode *node=(QNode*)malloc(sizeof(QNode));
    node->data=e;
    node->next = NULL;
    Q->rear->next=node; //插入节点
    Q->rear=node;   //更新尾指针
}

//遍历队列
void Traversal(QLink *Q){
    if (Q == NULL || Q->front == Q->rear)
    {
        printf("队列为空\n");
        return;
    }
    QNode *node=Q->front->next;
    while (node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
    
}

    // 出队
int DeQueue(QLink *Q,int *val)
{
    if (Q->front==Q->rear||Q==NULL)
    {
        return 0;
    }
    QNode *node=Q->front->next;
    *val=node->data;
    Q->front->next=node->next;
    if (Q->rear==node)
    {
        Q->rear=Q->front;
    }
    free(node);
    return 1;
}

//反转队列
void Reverse_Queue(QLink *Q){
    if (Q == NULL || Q->front == Q->rear)
    {
        return;
    }
    //要符合队列先进先出的规则
    int temp;
    //使用递归先出队然后再挨个入队
    DeQueue(Q,&temp);
    Reverse_Queue(Q);
    InQueue(Q,temp);
}

int main(){
    QLink *Q =init();
    for (int i = 0; i < 9; i++)
    {
        int random=100+rand()%900;
        InQueue(Q,random);
    }
    Traversal(Q);
    printf("\n");
    Reverse_Queue(Q);
    Traversal(Q);
}