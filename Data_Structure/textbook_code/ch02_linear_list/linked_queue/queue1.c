#include <stdio.h>
#include <stdlib.h>

typedef int EleType;

//创建两个结构体，一个是代表节点一个是代表队列
typedef struct queue_node{
    EleType data;
    struct queue_node *next;
}linked_queue;

typedef struct queue{
    linked_queue *front;
    linked_queue *rear;
}queue;

//初始化 动态分配内存
queue* init(){
    //先有队列再有节点再有里面的数据  带头节点
    queue *Q=(queue*)malloc(sizeof(queue));
    linked_queue *node=(linked_queue*)malloc(sizeof(linked_queue));
    node->data=0;
    node->next=NULL;
    Q->front=node;
    Q->rear=node;
    return Q;
}

//入队 使用尾插法
int inqueue(queue *Q,EleType e){
    //新建节点
    linked_queue *node=(*linked_queue)malloc(sizeof(linked_queue));
    node->data=e;
    node->next=NULL;
    Q->rear->next=node; //头节点的next存放新增节点地址
    Q->rear=node;       //更新尾指针位置
    return 1;
}

//出队
int dequeue(queue *Q,EleType *e){
    if (Q->front == Q->rear)
    {
        return 0;
    }
    linked_queue *node=Q->front->next;    //要释放的节点
    *e=node->data;
    Q->front->next=node->next;  //指向下一个节点
    if (Q->rear=node)       //删除的是尾节点的话就要头尾相等
    {
        Q->rear=Q->front;
    }
    free(node); //释放节点
    return 1; 
}
int main(){
    return 0;
}