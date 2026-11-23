#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElmType;

typedef struct link
{
    ElmType data;
    struct link *next;
} LNode, *LinkList;

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

// 创建节点
LNode *Create_Node(ElmType e)
{
    LNode *Node = (LNode *)malloc(sizeof(LNode));
    if (Node == NULL)
    {
        return NULL;
    }
    Node->data = e;
    Node->next = NULL;
    return Node;
}

// 使用头插法存入元素
void Head_Insert(LinkList L, ElmType e)
{
    LNode *node = Create_Node(e);
    node->next = L->next;
    L->next = node;
}

// 遍历链表
void Traversal(LinkList L)
{
    LinkList temp = L->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// 查找元素
int Link_Seek(LinkList L, ElmType e)
{
    if (L == NULL)
    {
        return -1;
    }
    LinkList temp = L->next;
    int cnt = 1;
    while (temp != NULL)
    {
        if (temp->data == e)
        {
            return cnt;
        }
        temp = temp->next;
        cnt++;
    }
    return -1;
}

// 为插入做准备需要先知道链表长度
int Link_Len(LinkList L)
{
    if (L == NULL)
    {
        return 0;
    }
    int cnt = 0;
    LinkList temp = L->next;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// 插入元素 要判断位置合理 >0 <len 插入后输出
int Link_Insert(LinkList L, int position, ElmType e)
{
    // 先获取链表长度
    int len = Link_Len(L);
    // 判断合理性
    LinkList temp = L;
    if (position > 0 && position <= len + 1)
    {
        for (int i = 0; i < position - 1; i++)
        {
            // 找到前一个节点
            temp = temp->next;
        }
    }
    else
    {
        return -1;
    }
    // 插入节点
    LNode *node = Create_Node(e);
    node->next = temp->next;
    temp->next = node;
    // 最后遍历输出
    Traversal(L);
    return 1;
}

// 删除元素
int Link_Delete(LinkList L, ElmType e)
{
    if (L == NULL)
    {
        return 0;
    }
    LinkList temp = L;
    while (temp->next != NULL)
    {
        if (temp->next->data == e)
        {
            // 先获得需要删除的节点
            LNode *node = temp->next;
            temp->next = node->next;
            free(node);
            Traversal(L);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// 反转链表 通过头插法不断往前插入
void Reverse_Link(LinkList L)
{
    LNode *Head = L;
    LNode *temp = L->next;
    Head->next = NULL;
    while (temp != NULL)
    {
        LinkList next = temp->next;
        LNode *node = temp;
        node->next = Head->next;
        Head->next = node;
        temp = next;
    }
    Traversal(L);
}

// 合并链表
LinkList List_Combine(LinkList L1, LinkList L2)
{
    // 从小到大使用头插法
    LNode *p = L1->next;
    LNode *q = L2->next;
    LNode *R = L1;
    R->next = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            // 头插法
            LNode *tmp = p; // 拿出当前这个节点
            p = p->next;    // p先在原链往前走一步！
            tmp->next = R->next;
            R->next = tmp;
        }
        else
        {
            LNode *tmp = q; // 拿出当前这个节点
            q = q->next;    // q先在原链往前走一步！
            tmp->next = R->next;
            R->next = tmp;
        }
    }
    while (p != NULL)
    {
        LNode *tmp = p;
        p = p->next;
        tmp->next = R->next;
        R->next = tmp;
    }
    while (q != NULL)
    {
        LNode *tmp = q;
        q = q->next;
        tmp->next = R->next;
        R->next = tmp;
    }
    free(L2);
    return L1;
}

// 分割函数
void Split_LinkList(LinkList L, ElmType e)
{
    // 先分成两端再拼到一起，只需取下一段，剩下的就是另一段，最后拼接在一起
    LNode *less_tail = L; // ≤e 这条链的尾，复用原表头
    LNode *great_head = NULL;
    LNode *great_tail = NULL;
    LNode *P = L->next;
    LNode *Next;

    L->next = NULL; // 先清空原链表的有效链

    while (P != NULL)
    {
        Next = P->next; // 先保存下一个，防止断链丢失
        if (P->data >= e)
        {
            // 接到大于e的链
            if (great_head == NULL)
            {
                great_head = P;
                great_tail = P;
            }
            else
            {
                great_tail->next = P;
                great_tail = P;
            }
            great_tail->next = NULL; // 截断，防止环
        }
        else
        {
            // 接到 <e 的链（原L）
            less_tail->next = P;
            less_tail = P;
            less_tail->next = NULL;
        }
        P = Next;
    }
    // 最后合并 小在前
    less_tail->next = great_head;
}

int main()
{
    LinkList L = Link_Init();
    // 设置随机种子
    srand((unsigned)time(NULL));
    // 生成随机数存入链表 （1）
    for (int i = 0; i < 10; i++)
    {
        int random = 100 + rand() % 900;
        Head_Insert(L, random);
    }
    // 输出链表 （2）
    Traversal(L);
    printf("\n");

    // 读入整数存在返回位置 （3）
    printf("请输入整数：");
    int val;
    scanf("%d", &val);
    int pos=Link_Seek(L, val);
    printf("%d\n",pos);

    // 读入整数和插入位置 （4）
    printf("请输入整数和插入位置：");
    int insert;
    int position;
    scanf("%d", &insert);
    scanf("%d", &position);
    Link_Insert(L, position, insert);
    printf("\n");

    // 删除整数  (5)
    printf("请输入整数：");
    int delete;
    scanf("%d", &delete);
    Link_Delete(L, delete);
    printf("\n");

    // 反转链表 （6）
    Reverse_Link(L);
    printf("\n");

    // 合并链表 （7）
    LinkList L1 = Link_Init();
    LinkList L2 = Link_Init();
    for (int i = 9; i > 0; i--)
    {
        Head_Insert(L1, i);
    }
    for (int i = 20; i > 10; i--)
    {
        Head_Insert(L2, i);
    }
    Traversal(L1);
    printf("\n");
    Traversal(L2);
    printf("\n");
    List_Combine(L1, L2);
    Traversal(L1);
}
