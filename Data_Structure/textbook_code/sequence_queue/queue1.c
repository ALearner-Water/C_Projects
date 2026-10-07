#include <stdio.h>
#define max 100
typedef int Type;

typedef struct seq_queue{
    Type data [max];
    int front;
    int rear;   //有最大容量和头尾指针  队是先进先出
}seq_queue;

//初始化
void init(seq_queue *Q){
    Q->front=0;
    Q->rear=0;
}

//判空，因为初始阶段front和rear的位置的是一样的，所以不是判断是否都为0，而是判断位置是否一样

//出队
Type dequeue(seq_queue *Q){
    //先判空
    if(Q->front==Q->rear){
        printf("empty\n");
        return 0;
    }
    //储存出队的数据然后头指针++    这样写会导致假溢出
    Type e=Q->data[Q->front];
    Q->front++;     
    return e;
}


//如果队列是假溢出应该如何处理
int full_queue(seq_queue *Q){
    if (Q->front>0)
    {
        int step=Q->front;
        for (int i = Q->front; i < Q->rear; i++)    //调整队列整体前移
        {
            Q->data[i-step]=Q->data[i];
        }
        Q->front=0;
        Q->rear=Q->rear-step;
        return 1;
    }
    else
    {
        printf("real full\n");
        return 0;
    }
    
}
//入队
int inqueue(seq_queue *Q,Type e){
    if (Q->rear>=max)
    {
        if (!full_queue(Q))
        {
            return 0;
        }
        
    }
    Q->data[Q->rear]=e;
    Q->rear++;
    return 1;
}

//获取队头数据
Type getitem(seq_queue *Q){
    if (Q->front == Q->rear)
    {
        printf("empty\n");
        return 0;
    }
    Type e=Q->data[Q->front];
    return e;
}