#include <stdio.h>
#include <stdlib.h>
typedef char ElimType;
typedef struct BiTree{
    ElimType data;
    struct BiTree *left_child;
    struct BiTree *right_child;
    int ltag;    //0为左孩子 1为前驱
    int rtag;    //0为右孩子 1为后继
}*BiTree,BiTNode;

// 用广义表创建二叉树
BiTree Create_Tree(char str[])
{
    // 用栈存父节点
    BiTree stack[100];
    int pointer = -1;
    // 标记是左孩子还是右孩子
    int k;
    // 新建树
    BiTree T = NULL;
    // 临时变量
    BiTree P;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            // 是字符就创建节点
            P = (BiTree)malloc(sizeof(BiTNode));
            P->data = ch;
            P->left_child = NULL;
            P->right_child = NULL;
            P->ltag=0;
            P->rtag=0;

            if (T == NULL)
            {
                // 此时为根节点
                T = P;
            }
            else
            {
                // 看标记k，是左孩子还是右孩子 是要给栈顶节点挂接
                if (k == 1)
                {
                    stack[pointer]->left_child = P;
                }
                else
                {
                    stack[pointer]->right_child = P;
                }
            }
        }
        else if (ch == '(')
        {
            // 碰到左括号就入栈
            stack[++pointer] = P;
            // 下一个是左孩子
            k = 1;
        }
        else if (ch == ',')
        {
            // 碰到右孩子
            k = 2;
        }
        else if (ch == ')')
        {
            // 右括号出栈
            pointer--;
        }
    }
    return T;
}

// 递归中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->left_child);
        printf("%c ", T->data);
        InOrder(T->right_child);
    }
}

//线索化具体流程 中序
void InThread(BiTree T,BiTree *pre){
    if (T!=NULL)
    {
        //先找到最左边
        InThread(T->left_child,pre);
        //赋值前驱
        if (T->left_child==NULL)
        {
            T->ltag=1;
            T->left_child=*pre;
        }
        //赋值后继 对pre
        if ((*pre)->right_child==NULL)
        {
            (*pre)->rtag=1;
            (*pre)->right_child=T;
        }
        //更新前驱
        (*pre)=T;
        //对右子树做同样处理
        InThread(T->right_child,pre);
    }
}

//建完树之后对树进行线索化
BiTree InOrderThreading(BiTree T){
    //分配头节点的内存
    BiTree Thrt = (BiTree)malloc(sizeof(BiTNode));
    Thrt->ltag=0;
    Thrt->rtag=1;
    //头节点的左孩子就为T
    Thrt->left_child=T;
    if (T == NULL)
    {
        // 空树：头结点自环
        Thrt->right_child = Thrt;
    }
    else
    {
        //第一个前驱为Thrt
        BiTree pre=Thrt;
        //进行线索化
        InThread(T,&pre);
        pre->rtag=1;
        pre->right_child=Thrt;
        Thrt->right_child=pre;
    }
    return Thrt;    //返回头节点
}

// 找结点p的中序前驱
BiTree FindPre(BiTree p)
{
    if (p->ltag == 1)
    {
        // 左是线索，直接就是前驱
        return p->left_child;
    }
    else
    {
        // 有左孩子：左子树一直往右走到底
        BiTree q = p->left_child;
        while (q->rtag == 0)
            q = q->right_child;
        return q;
    }
}

// 找结点p的中序后继
BiTree FindNext(BiTree p)
{
    if (p->rtag == 1)
    {
        // 右是线索，直接是后继
        return p->right_child;
    }
    else
    {
        // 有右孩子：右子树一直往左走到底
        BiTree q = p->right_child;
        while (q->ltag == 0)
            q = q->left_child;
        return q;
    }
}

int main(){
    char ch[100] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    BiTree t = Create_Tree(ch);
    InOrder(t);
    printf("\n");
    BiTree p=InOrderThreading(t);
    BiTree pre_node = FindPre(p->left_child);
    BiTree next_node = FindNext(p->left_child);
    printf("根结点%c 的前驱：%c\n", p->left_child->data, pre_node->data);
    printf("根结点%c 的后继：%c\n", p->left_child->data, next_node->data);
    printf("\n");
    return 0;
}