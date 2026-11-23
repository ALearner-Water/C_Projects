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

//生成节点
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
int main(){
    LinkList L = Link_Init();
    // 设置随机种子
    srand((unsigned)time(NULL));
    // 生成随机数存入链表 （1）
    for (int i = 0; i < 10; i++)
    {
        int random = 100 + rand() % 900;
        Head_Insert(L, random);
    }
    Traversal(L);
    printf("\n");
    printf("输入分割数\n");
    int split;
    scanf("%d",&split);
    Split_LinkList(L,split);
    Traversal(L);
}