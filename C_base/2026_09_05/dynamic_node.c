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
    struct Node *node=create_node(42);
    if(node==NULL){
        return 1;
    }
    printf("%d",node->data);
    destroy_node(node);
    node=NULL;
    return 0;
}