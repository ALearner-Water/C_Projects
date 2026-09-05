#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
};
int main(void){
    struct Node node1={10,NULL};
    struct Node node2={20,NULL};
    node1.next=&node2;
    printf("%d\n", node1.next->data);
    printf("%d",node2.next==NULL);
    return 0;
}