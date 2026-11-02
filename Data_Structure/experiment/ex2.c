#include <stdio.h>
#include <stdlib.h>
typedef int ElType;

typedef struct stack{
    struct stack *next;
    ElType data;
}*Stack,Node;

//初始化 带头节点
Stack init(){
    Stack s=(Node*)malloc(sizeof(Node));
    if (s==NULL)
    {
        return NULL;
    }
    s->next=NULL;
    return s;
} 

//入栈
void Push(Stack S,ElType e){
    //新建节点
    Node *node=(Node*)malloc(sizeof(Node));
    if (node==NULL)
    {
        return;
    }
    node->data=e;
    node->next=S->next;
    S->next=node;
}

//出栈
void Pop(Stack S){
    if (S->next==NULL)
    {
        return;
    }
    //拿到栈顶指针
    Node *n=S->next;
    printf("%d ",n->data);
    //移动栈顶指针
    S->next=n->next;
    //将出栈的节点释放
    free(n);
}

int main(){
    Stack S=init();
    //生成随机数
    for (int i = 0; i < 10; i++)
    {
        int random=100+rand()%900;
        Push(S,random);       //入栈
    }
    //出栈
    for (int i = 0; i < 10; i++)
    {
        Pop(S);
    }
    
}