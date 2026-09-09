#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

struct Node * create_node(int val){
    Node *L=malloc(sizeof(Node));
    if (L==NULL){
        printf("失败");
        return NULL;
    }
    L->data=val;
    L->next=NULL;
    return L;
}

void destroy_list(Node *head){
    //先保存后继再销毁当前再等于后继
    Node *current=head;
    while (current!=NULL)
    {
        Node *nex=current->next;
        free(current);
        current=nex;
    }
}
int main(void){
    Node *L=create_node(10);
    if (L==NULL)
    {
        printf("L为空");
        return 1;
    }
    
    printf("%d\n",L->data);
    destroy_list(L);
    L=NULL;
    destroy_list(L);
    return 0;
}