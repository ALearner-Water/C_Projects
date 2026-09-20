#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int TYPE;

typedef struct linked_list
{
    TYPE data;
    struct linked_list *next;
}linked_list;

//链栈没有头节点，直接从首元节点开始
linked_list* init(){
    //链栈初始化没有节点直接置为空即可，后面新入栈的再分配节点
    return NULL;
}

//入栈使用头插法 需要二级指针
int push(linked_list **L,TYPE data){
    linked_list *NEW=(*linked_list)malloc(sizeof(linked_list));
    if (NEW == NULL)
    {
        printf("malloc fail\n");
        return 0;
    }
    NEW->data=data;
    NEW->next=*L;
    *L = NEW;
    return 1;
}

//出栈也需要二级指针 因为需要修改top指针的值
int pop(linked_list **L, TYPE *e){
    if (*L == NULL) // *L是栈顶，等于NULL代表空栈
    {
        printf("empty stack\n");
        return 0;
    }
    //保留后继删除前趋
    linked_list *del=*L;
    *e=del->data;
    *L = del->next;
    free(del);
    return 1;
}

//取栈顶元素 只读不需要二级指针因为不需要修改值
int GetTop(linked_list *L,TYPE *e){
    if (L == NULL) 
    {
        printf("empty stack\n");
        return 0;
    }
    *e=L->data
    return 1;
}

//销毁栈
void destroy(linked_list **L){
    while (*L!=NULL)
    {
        linked_list *del=*L;
        *L=del->next;
        free(del);
    }
}