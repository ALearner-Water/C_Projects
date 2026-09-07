#include <stdio.h>
#include <stdlib.h>
//创建节点
struct Node{
    int data;
    struct Node *next;
};
//初始化节点
struct Node *create_node(int val){
    struct Node *node=malloc(sizeof *node);
    if(node==NULL){
        printf("分配失败");
        return NULL;
    }
    node->data=val;
    node->next=NULL;
    return node;
}
//释放内存
void destroy_node(struct Node *node){
    free(node);
}
//释放链表
void destroy_list(struct Node *head){
    struct Node *current=head;
    while (current!=NULL)
    {
        struct Node *nex=current->next;
        destroy_node(current);
        current=nex;
    }
    
}
int main(void){
    struct Node *head=create_node(10);
    if(head==NULL){
        return 1;
    }
    head->next=create_node(20);
    if (head->next == NULL)
    {
        destroy_list(head);     //分配内存失败直接释放  
        return 1;
    }
    head->next->next=create_node(30);
    if (head->next->next == NULL)
    {
        destroy_list(head);
        return 1;
    }
    struct Node *current=head;
    while (current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    destroy_list(head);
    head=NULL;
    return 0;
}