#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef int Type;

typedef struct seq_queue
{
    Type *data;
    int front;
    int rear; // 有最大容量和头尾指针  队是先进先出
} seq_queue;        //循环队列解决假溢出问题

seq_queue* init(){
    seq_queue *Q=(*seq_queue)malloc(sizeof(seq_queue));
    Q->data=(*Type)malloc((sizeof(Type)*max));
    Q->front=0;
    Q->rear=0;
    return Q;
}

//入队
int inqueue(seq_queue *Q,Type e){
    if ((Q->rear+1)%max==0)
    {
        printf("full\n");
        return 0;
    }
    Q->data[Q->rear]=e;
    Q->rear = (Q->rear + 1) % max;      //通过取余来做循环
    return ;
}

//出队
int dequeue(seq_queue *Q,Type *e){
    if (Q->front==Q->rear)
    {
        printf("empty\n");
        return 0;
    }
    *e=Q->data[Q->front];
    Q->front = (Q->front + 1) % max; // 通过取余来做循环
    return 1;
}