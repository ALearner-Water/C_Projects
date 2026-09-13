#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *create_empty_list(void){
    Node *L=malloc(sizeof(Node));
    if (L==NULL)
    {
        return NULL;
    }
    L->data=0;
    L->next=NULL;
    return L;
}
bool insert_after(Node *previous, int value){
    if (previous==NULL)
    {
        return false;
    }else{
        Node *new=create_empty_list();
        if (new==NULL)
        {
            return false;
        }else
        {
            new->data = value;
            new->next=previous->next;
            previous->next=new;
            return true;
        }
    }
    
}
void destroy_list(Node *head){
    Node *current=head;
    while (current!=NULL)
    {
        Node *nex=current->next;
        free(current);
        current=nex;

    }
    
}
bool insert_at(Node *head, int position, int value){
    if (head==NULL||position<1)
    {
        return false;
    }else{
        Node *current=head;
        for (int i = 0; i < position-1; i++)
        {
            current=current->next;
            if (current == NULL)
            {
                return false;
            }
        }
       return insert_after(current,value);
    }
    
}
int main(void){
    Node *head=create_empty_list();
    if (head==NULL)
    {
        return 1;
    }
    if(!insert_at(head,1,10)){
        destroy_list(head);
        return 1;
    }
    if (!insert_at(head, 2, 20))
    {
        destroy_list(head);
        return 1;
    }
    if (!insert_at(head, 3, 30))
    {
        destroy_list(head);
        return 1;
    }
    if (insert_at(head, 5, 30))
    {
        destroy_list(head);
        return 1;
    }
    Node *current=head->next;
    while (current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    destroy_list(head);
    head=NULL;
    return 0;
}