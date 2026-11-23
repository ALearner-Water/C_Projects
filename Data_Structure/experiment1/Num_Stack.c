#include "Num_Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//数据栈
// 初始化 带头节点
Stack Num_init()
{
    Stack s = (Node *)malloc(sizeof(Node));
    if (s == NULL)
    {
        return NULL;
    }
    s->next = NULL;
    return s;
}

// 入栈
void Num_Push(Stack S, ElmType e)
{
    // 新建节点
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        return;
    }
    node->data = e;
    node->next = S->next;
    S->next = node;
}

// 出栈
Node *Num_Pop(Stack S)
{
    if (S->next == NULL)
    {
        return NULL;
    }
    // 拿到栈顶指针
    Node *n = S->next;
    // 移动栈顶指针
    S->next = n->next;
    return n;
}

// int main(){
//     // 设置随机种子
//     srand((unsigned)time(NULL));
//     Stack stack1=Num_init();
//     for (int i = 0; i < 10; i++)
//     {
//         int random = 100 + rand() % 900;
//         Num_Push(stack1,random);
//     }
//     while (stack1->next!=NULL)
//     {
//         Node *node =Num_Pop(stack1);
//         printf("%.1f ",node->data);
//     }
// }
