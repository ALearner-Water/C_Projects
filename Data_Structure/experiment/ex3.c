#include <stdio.h>
#include <stdlib.h>
typedef int ElType;

//定义队列节点
typedef struct queue{
    struct queue *next;
    ElType data;
}QNode;

//再定义头尾指针 这是队列结构
typedef struct link_q{
    QNode *front;
    QNode *rear;
}QLink;

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
QNode *DeQueue(QLink *Q)
{
    if (Q->front==Q->rear||Q==NULL)
    {
        return NULL;
    }
    QNode *node=Q->front->next;
    Q->front->next=node->next;
    if (Q->rear==node)
    {
        Q->rear=Q->front;
    }
    return node;
}

//反转队列
void Reverse_Queue(QLink *Q){
    if (Q == NULL || Q->front == Q->rear)
    {
        return;
    }
    //使用头插法不断插入
    QNode *node=NULL;
    QNode *de_node;
    //将出队的元素插入链表
    while ((de_node=DeQueue(Q))!=NULL)
    {
        de_node->next=node;
        node=de_node;
    }
    //最后拼接
    Q->front->next=node;
    //重新定位尾指针
    Q->rear=Q->front;
    while (Q->rear->next!=NULL)
    {
        Q->rear=Q->rear->next;
    }
}

int main(){
    QLink *Q =init();
    for (int i = 0; i < 3; i++)
    {
        int random=100+rand()%900;
        InQueue(Q,random);
    }
    Traversal(Q);
    printf("\n");
    Reverse_Queue(Q);
    Traversal(Q);
}