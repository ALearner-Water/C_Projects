/*线性表的链表实现
1. 随机函数生成10个三位整数 存于链表
2. 输出链表内容
3. 读入整数 查看是否存在链表 返回位置或-1
4. 读入整数与插入位置 插入后输出链表内容，判断插入是否合理
5. 读入整数，删除后输出链表 或者返回-1
6.链表反转不占用新存储空间，输出链表
7. 合并两个非递减有序链表成非递增有序链表，允许有重复数据*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElmType;

typedef struct link
{
    ElmType data;
    struct link *next;
}LNode, *LinkList;

// 初始化链表
LinkList Link_Init()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return NULL;
    }
    L->data = 0;
    L->next = NULL;
    return L;
}

//创建节点
LNode* Create_Node(ElmType e){
    LNode *Node = (LNode*)malloc(sizeof(LNode));
    if (Node == NULL)
    {
        return NULL;
    }
    Node->data = e;
    Node->next = NULL;
    return Node;
}

//使用头插法存入元素
void Head_Insert(LinkList L,ElmType e){
    LNode *node=Create_Node(e);
    node->next=L->next;
    L->next=node;
}

//遍历链表
void Traversal(LinkList L){
    LinkList temp=L->next;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//查找元素
int Link_Seek(LinkList L,ElmType e){
    LinkList temp = L->next;
    int cnt=1;
    while (temp != NULL)
    {
        if (temp->data==e)
        {
            return cnt;
        }
        temp = temp->next;
        cnt++;
        
    }
    return -1;
}

//为插入做准备需要先知道链表长度
int Link_Len(LinkList L)
{
    int cnt=0;
    LinkList temp = L->next;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

//插入元素 要判断位置合理 >0 <len 插入后输出
int Link_Insert(LinkList L ,int position,ElmType e){
    //先获取链表长度
    int len = Link_Len(L);
    //判断合理性
    LinkList temp = L;
    if (position > 0 && position <= len+1)
    {
        for (int i = 0; i < position-1; i++)
        {
            //找到前一个节点
            temp=temp->next;
        }     
    }else{
        return -1;
    }
    //插入节点
    LNode *node = Create_Node(e);
    node->next = temp->next;
    temp->next = node;
    //最后遍历输出
    Traversal(L);
    return 1;
}

//删除元素
int Link_Delete(LinkList L,ElmType e){
    LinkList temp=L;
    while (temp->next!=NULL)
    {
        if (temp->next->data==e)
        {
            //先获得需要删除的节点
            LNode *node=temp->next;
            temp->next=node->next;
            free(node);
            Traversal(L);
            return 1;
            
        }
        temp=temp->next;
    }
    return 0;
}

//反转链表 通过头插法不断往前插入
void Reverse_Link(LinkList L){
    LinkList Head=L;
    LinkList temp = L->next;
    Head->next=NULL;
    while (temp!=NULL)
    {
        LinkList next=temp->next;
        LNode *node=temp;
        node->next=Head->next;
        Head->next=node;
        temp=next;
    }
    Traversal(L);
}

int main(){
    LinkList L=Link_Init();
    Head_Insert(L,3);
    Head_Insert(L,4);
    int position=Link_Seek(L,3);
    printf("位置为%d\n",position);
    Link_Insert(L,3,5);
    printf("\n");
    Link_Delete(L,3);
    printf("\n");
    Reverse_Link(L);
}