#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int Type;

//定义结构体
typedef struct seq_stack{
    //栈里面需要有栈底和栈顶两个指针还需要栈的容量
    Type *top;
    Type *base;
    int stacksize;
}seq_stack;

//初始化
seq_stack* init(){
    seq_stack *L=(seq_stack*)malloc(sizeof(seq_stack));
    if(L==NULL){
        printf("fail malloc *L")
        return NULL;
    }
    L->base=(Type *)malloc(sizeof(Type)*MAXSIZE);   //给栈开辟空间存储数据
    if (L->base==NULL)
    {
        free(L);
        printf("fail malloc *base");
        return NULL;
    }
    L->top=L->base;
    L->stacksize=MAXSIZE;
    return L;
}

//入栈
int push(seq_stack *L,Type data){
    if (L==NULL)
    {
     printf("not init");
     return 0;   
    }
    if (L->top-L->base==L->stacksize)
    {
        printf(" stack full");
        return 0;
    }
    *(L->top)=data; //直接将数据写入top然后top自增
    L->top++;
    return 1;
}

//出栈
int pop(seq_stack *L,Type *e){
    if (L == NULL)
    {
        printf("not init");
        return 0;
    }
    if (L->top==L->base)
    {
        printf("empty stack");
        return 0;
    }
    *e=*(L->top-1);
    L->top--;
    return 1;
}

//取栈顶元素
int GetTop(seq_stack *L,Type *e){
    if (L == NULL)
    {
        printf("not init");
        return 0;
    }
    if (L->top == L->base)
    {
        printf("empty stack");
        return 0;
    }
    *e=*(L->top-1);
    return 1;
}

//释放顺序栈
int destory_stack(seq_stack *L){
    if (L == NULL){
        return 0;
    }
    //释放存放数据的数组
    free(L->base);
    //释放存放数据的结构体本身
    free(L);
}