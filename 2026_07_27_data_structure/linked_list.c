#include <stdio.h>
#include <stdlib.h>
//链表由两部分：1.数据本身，2.下一个数据位置
typedef int Type;
typedef struct linked_list{
    Type data;          //数据本身
    struct linked_list*next;  //下一个数据位置
}linked_list; 

//对链表进行初始化，头节点数据为0，下一个数据位置为null
linked_list *initList(){    //使用指针来动态分配内存
    linked_list *HEAD=(linked_list*)malloc(sizeof(linked_list));
    HEAD->data=0; 
    HEAD->next=NULL;
    return HEAD;    //返回指针后续直接使用
}

//使用头插法插入数据 插入位置是头节点的后继
void Headinsert(linked_list *L,Type e){  //传进来的是一个头节点，可以认为是一个链表
    linked_list *p=(linked_list*)malloc(sizeof(linked_list));   //新节点
    p->data=e;          //存放数据
    p->next=L->next;    //始终让头节点指向新插入的接节点然后始终让插入节点指向下一个节点
    L->next=p;
}

//遍历链表
void traversal(linked_list *HEAD){
    //需要临时指针
    linked_list *p=HEAD->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

//尾插法前置需要获取尾节点
linked_list *Tail(linked_list *head){
    linked_list *p=head;
    while (p->next!=NULL)
    {
     p=p->next;   
    }
    return p;

}

//尾插法插入
void TailInsert(linked_list *L,Type e){
    linked_list *q=Tail(L); //尾节点
    linked_list *p=(linked_list*)malloc(sizeof(linked_list)); //新建节点
    p->data=e;
    q->next=p;
    p->next=NULL;   //尾插法的最后一个指向的永远是空

}

//指定位置插入
int Insert(linked_list* p,int position,Type e){
    if(position<0){
        printf("传入失败\n");
        return 0;
    }
    linked_list *q=p;   //创建临时指针，以免修改外部链表指针
    //先找到插入位置的前一个节点
    for(int i=0;i<position-1;i++){  //忽略头节点，位置从第一个有效节点开始算
        q=q->next;
        if(q==NULL){    //到尾节点了
            return 0;
        }
    }
    linked_list *New=(linked_list *)malloc(sizeof(linked_list));  //新节点
    New->next=q->next;
    New->data=e;
    q->next=New;
}

int main(){
    linked_list *l=initList();
    Headinsert(l,30);
    Headinsert(l,40);
    TailInsert(l,50);
    TailInsert(l,111);
    Insert(l,3,1234);
    traversal(l);
}
