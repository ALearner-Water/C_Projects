#include <stdio.h>
#include <stdlib.h>
// 链表由两部分：1.数据本身，2.下一个数据位置
typedef int Type;
typedef struct linked_list
{
    Type data;                // 数据本身
    struct linked_list *next; // 下一个数据位置
} linked_list;

// 对链表进行初始化，头节点数据为0，下一个数据位置为null
linked_list *initList()
{ // 使用指针来动态分配内存
    linked_list *HEAD = (linked_list *)malloc(sizeof(linked_list));
    HEAD->data = 0;
    HEAD->next = NULL;
    return HEAD; // 返回指针后续直接使用
}

// 使用头插法插入数据 插入位置是头节点的后继
void Headinsert(linked_list *L, Type e)
{                                                                // 传进来的是一个头节点，可以认为是一个链表
    linked_list *p = (linked_list *)malloc(sizeof(linked_list)); // 新节点
    p->data = e;                                                 // 存放数据
    p->next = L->next;                                           // 始终让头节点指向新插入的接节点然后始终让插入节点指向下一个节点
    L->next = p;
}

// 遍历链表
void traversal(linked_list *HEAD)
{
    // 需要临时指针
    linked_list *p = HEAD->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 尾插法前置需要获取尾节点
linked_list *Tail(linked_list *head)
{
    linked_list *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 尾插法插入
void TailInsert(linked_list *L, Type e)
{
    linked_list *q = Tail(L);                                    // 尾节点
    linked_list *p = (linked_list *)malloc(sizeof(linked_list)); // 新建节点
    p->data = e;
    q->next = p;
    p->next = NULL; // 尾插法的最后一个指向的永远是空
}

// 指定位置插入
int Insert(linked_list *p, int position, Type e)
{
    if (position < 0)
    {
        printf("传入失败\n");
        return 0;
    }
    linked_list *q = p; // 创建临时指针，以免修改外部链表指针
    // 先找到插入位置的前一个节点
    for (int i = 0; i < position - 1; i++)
    { // 忽略头节点，位置从第一个有效节点开始算
        q = q->next;
        if (q == NULL)
        { // 到尾节点了
            return 0;
        }
    }
    linked_list *New = (linked_list *)malloc(sizeof(linked_list)); // 新节点
    New->next = q->next;
    New->data = e;
    q->next = New;
    return 1;
}

// 删除节点
int delete(linked_list *head, int position)
{
    if (head == NULL)
    {
        printf("链表为空，无法删除\\n");
        return 0;
    }
    if (position < 0)
    {
        printf("传入失败\n");
        return 0;
    }
    // 先找到要删除的前置节点，然后记录下来，最后改变指向关系并free
    linked_list *L = head;
    for (int i = 0; i < position - 1; i++)
    {
        L = L->next;
        if (L == NULL)
        { // 到尾节点了
            return 0;
        }
    } // 获取到前继节点
    if (L->next == NULL)
    {
        printf("删除位置错误\n");
        return 0;
    }
    linked_list *delete = L->next; // 获取到要删除的节点
    L->next = delete->next;        // 指向后继节点
    free(delete);
    return 1;
}

// 获取链表长度
int length(linked_list *head)
{
    int len = 0;
    linked_list *L = head->next; // 除去头节点
    while (L != NULL)
    { // L==null 指针没有指向任何节点
        L = L->next;
        len++;
    }
    return len;
}

//用最小的时间复杂度来找倒数第k个节点  用双指针的方法让两个指针始终相隔k步这样遍历一次就可以找到
int find_data(linked_list *L,int k){
    if(L==NULL||k<0||k>length(L)){
        printf("无效");
        return 0;
    }
    //定义两个快慢指针
    linked_list *slow=L->next;
    linked_list *fast=L->next;
    for(int i=0;i<k;i++){
        fast=fast->next;    //先让快指针走k步
    }
    while (fast!=NULL)
    {
        //这时候快慢一起动就可以找到倒数第k个了
        fast=fast->next;
        slow=slow->next;
    }
    printf("倒数第k个的值为：%d",slow->data);
    return 1;
}

//反转链表
linked_list * reverse1(linked_list *L){
    //使用头插法反转
    linked_list *p=L;   
    linked_list *q=p->next;
    p->next = NULL ;// 先断开头节点
    while (q!=NULL)
    {
        linked_list *net=q->next;
        q->next=p->next;
        p->next=q;
        q=net;
    }
    return p;
}
linked_list * reverse2(linked_list *L){
    //使用三指针遍历
    
}
int main()
{
    linked_list *l = initList();
    Headinsert(l, 30);
    Headinsert(l, 40);
    TailInsert(l, 50);
    TailInsert(l, 111);
    Insert(l, 3, 1234);
    delete(l, 3);
    printf("长度为%d\n", length(l));
    traversal(l);
    find_data(l,2);
    printf("\n");
    linked_list *p=reverse(l);
    traversal(p);
}
