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
    if (L == NULL)
    {
        return 0;
    }
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
int Link_Len(LinkList L){
    if (L==NULL)
    {
        return 0;
    }
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
    if (L == NULL)
    {
        return 0;
    }
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

//合并链表
LinkList List_Combine(LinkList L1,LinkList L2){
    //创建2个遍历指针和一个合并链指针
    LNode *t1=L1->next;
    LNode *t2=L2->next;
    LNode *R=L1;    //从头节点开始
    while (t1!=NULL&&t2!=NULL)
    {
        if (t1->data>=t2->data) //递减链表
        {
            R->next=t1; //将大的接入
            R=t1;   //更新尾节点指向t1
            t1=t1->next;
        }
        else{
            R->next=t2; //否则接入t2
            R = t2;     // 更新尾节点指向t2
            t2=t2->next;
        }
    }
    //将剩下的节点再接入
    if (t1!=NULL)
    {
        R->next=t1;
    }else{
        R->next=t2;
    }
    free(L2);        //L2上面已经没有节点了需要free，以免内存泄漏
    return L1;
}

// 分割函数
void Split_LinkList(LinkList L, ElmType e)
{
    // 先分成两端再拼到一起
    LNode *max_head = NULL; // 大链的头尾指针
    LNode *max_tail = NULL;
    LNode *min_head = NULL; // 小链的头尾指针
    LNode *min_tail = NULL;
    LNode *P = L->next; // 指向链表的指针
    while (P != NULL)
    {
        // 先存好下一个节点位置
        LNode *next = P->next;
        // 拼接大链
        if (P->data >= e)
        {
            if (max_tail == NULL)
            {
                max_head = max_tail = P;
            }
            else
            {
                max_tail->next = P; // 尾插法
                max_tail = P;       // 更新尾节点
            }
        }
        // 拼接小链
        else
        {
            if (min_tail == NULL)
            {
                min_head = min_tail = P;
            }
            else
            {
                min_tail->next = P; // 尾插法
                min_tail = P;       // 更新尾节点
            }
        }
        P = next;
    }
    // 合并两条链
    if (min_tail != NULL)
    {
        // 有小于e的节点：小链 + 大链
        L->next = min_head;
        min_tail->next = max_head;
    }
    else
    {
        // min链为空，没有小于e的节点，直接接大链
        L->next = max_head;
    }
}

int main(){
    LinkList L=Link_Init();
    //生成随机数存入链表
    for (int i = 0; i < 10; i++)
    {
        int random=100+rand()%900;
        Head_Insert(L,random);
    }
    Traversal(L);
    printf("请输入分隔值：");
    int split=0;
    scanf("%d",&split);
    Split_LinkList(L,split);
    Traversal(L);
}