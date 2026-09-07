#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *create_node(int data){
    Node *L=(Node*)malloc(sizeof(Node));
    if(L==NULL){
        printf("失败");
        return NULL;
    }
    L->next=NULL;
    L->data=data;
    return L;
}

void destroy_list(Node *head){
    Node *current=head;
    while (current!=NULL)
    {
        //先保存后继再释放当前最后再移到后继
        Node *nex=current->next;
        free(current);
        current=nex;
    }
    
}

int main(){
    Node *L=create_node(7);
    if (L == NULL)
    {
        printf("失败");
        return 0;
    }
    L->next=create_node(9);
    if (L->next == NULL)
    {
        printf("失败");
        destroy_list(L);    //创建失败，第一个节点也要释放掉
        return 0;
    }
    Node *current=L;
    while (current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
        
    destroy_list(L);
    L=NULL;
    destroy_list(L);

}
