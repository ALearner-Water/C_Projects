#include <stdio.h>
#include <stdlib.h>

typedef char ElmType;
typedef struct BiTNode
{
    ElmType data;
    struct BiTNode *left_child;
    struct BiTNode *right_child;
}BiTNode,*BiTree;

//用广义表创建二叉树
BiTree Create_Tree(char str[]){
    //用栈存父节点
    BiTree stack[100];
    int pointer=-1;
    //标记是左孩子还是右孩子
    int k;
    //新建树
    BiTree T=NULL;
    //临时变量
    BiTree P;
    for (int i = 0; str[i]!='\0'; i++)
    {
        char ch=str[i];
        if (ch>='A' && ch<='Z')
        {
            //是字符就创建节点
            P=(BiTree)malloc(sizeof(BiTNode));
            P->data=ch;
            P->left_child=NULL;
            P->right_child=NULL;

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
        else if (ch=='(')
        {
            //碰到左括号就入栈
            stack[++pointer]=P;
            //下一个是左孩子
            k=1;
        }
        else if (ch==',')
        {
            //碰到右孩子
            k=2;
        }
        else if (ch==')')
        {
            //右括号出栈
            pointer--;
        }
        
    }
    return T;
}

//查找节点左右孩子
void Search_Child(BiTree T,char ch){
    BiTree p=T;
    //使用先序遍历找出
    BiTree stack[100];
    int pointer=-1;
    //根节点就是
    if (T->data==ch)
    {
        printf("左：%c,右：%c\n",T->left_child->data,T->right_child->data);
        return;
    }
    //直接入栈出栈查找
    else{
        stack[++pointer]=p;
        while (pointer!=-1)
        {
            p=stack[pointer--];
            if (p->data==ch)
            {
                char lch = (p->left_child != NULL) ? p->left_child->data : '#';
                char rch = (p->right_child != NULL) ? p->right_child->data : '#';
                printf("左：%c, 右：%c\n", lch, rch);
                return;
            }
            if (p->right_child!=NULL)
            {
                stack[++pointer]=p->right_child;
            }
            if (p->left_child!=NULL)
            {
                stack[++pointer]=p->left_child;
            }
        }
    }
    //没找到
    printf("没有匹配节点\n");
    return;
}

//统计节点个数 叶子节点个数 度和高度
void Statistics(BiTree T){
    // 总节点数
    int all_cnt = 0;
    // 叶子节点数
    int leaf = 0;
    // 度数
    int max_deg = 2;
    if (T == NULL)
    {
        return;
    }
    BiTree stack[100];
    int pointer = -1;
    BiTree p = T;
    stack[++pointer] = p;
    while (pointer != -1)
    {
        // 出栈多少个就有多少个节点
        p = stack[pointer--];
        all_cnt++;
        if (p->left_child==NULL&&p->right_child==NULL)
        {
            leaf++;
        }
        // 计算当前结点的度
        int cur_deg = 0;
        if(p->left_child != NULL) {
            cur_deg++;
        }
        if(p->right_child != NULL) {
            cur_deg++;
        }
        // 更新最大度
        if(cur_deg > max_deg) {
            max_deg = cur_deg;
        }
        if (p->right_child != NULL)
        {
            stack[++pointer] = p->right_child;
        }
        if (p->left_child != NULL)
        {
            stack[++pointer] = p->left_child;
        }
    }
    printf("总节点数为 %d,叶子节点数 %d,度为 %d,",all_cnt,leaf,max_deg);
}

//求树高度
int TreeHeight(BiTree T)
{
    if (T == NULL) // 没有结点，空的地方
    {
        return 0; // 空的高度记为0
    }
    int left_h = TreeHeight(T->left_child);           // 查左子树高度
    int right_h = TreeHeight(T->right_child);         // 查右子树高度
    return 1 + (left_h > right_h ? left_h : right_h); // 我自己这一层 + 最高的那一边
}

// 递归先序遍历
void PreOrder(BiTree T)
{
    if(T!=NULL){
        printf("%c ",T->data);
        PreOrder(T->left_child);
        PreOrder(T->right_child);
    }
}

//递归中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->left_child);
        printf("%c ", T->data);
        InOrder(T->right_child);
    }
}

//递归后序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->left_child);
        PostOrder(T->right_child);
        printf("%c ", T->data);
    }
}

//非递归先序遍历
void PreOrder_Stack(BiTree T){
    if (T==NULL)
    {
        return;
    }
    //定义栈来存放
    BiTree stack[100];
    int pointer=-1;
    //定义临时指针p指向T
    BiTree p=T;
    //先入栈让栈有任务
    stack[++pointer]=p;
    //再不断入栈出栈
    while (pointer!=-1)
    {
        p=stack[pointer--];
        printf("%c ",p->data);
        //因为先打印左孩子所以先入右孩子
        if (p->right_child!=NULL)
        {
            stack[++pointer]=p->right_child;
        }
        if (p->left_child != NULL)
        {
            stack[++pointer] = p->left_child;
        }
    }
}

// 非递归中序遍历
void InOrder_Stack(BiTree T){
    //也需要定义栈来存数据
    if (T == NULL)
    {
        return;
    }
    // 定义栈来存放
    BiTree stack[100];
    int pointer = -1;
    BiTree p=T;
    //将左孩子一直放入，没有之后就出栈，处理完之后对右孩子也是一样的做法，把右孩子当成根节点
    // 条件：p还有节点要走 或者 栈里还有节点没访问
    while (p != NULL || pointer != -1)
    {
        // 一路向左，把沿途所有节点全部压进栈
        while (p != NULL)
        {
            stack[++pointer] = p;
            p = p->left_child;
        }
        // 左走到尽头了，弹出栈顶（这就是根），访问
        p = stack[pointer--];
        printf("%c ", p->data);
        // 处理右子树，把右子树当成新的p
        p = p->right_child;
    }
}

//非递归后序遍历
void PostOrder_DoubleStack(BiTree T)
{
    if (T == NULL)
        return;
    BiTree s1[100], s2[100];
    int pointer1 = -1, pointer2 = -1;

    s1[++pointer1] = T;
    while (pointer1 != -1)
    {
        //根出栈压入s2
        BiTree p = s1[pointer1--];
        s2[++pointer2] = p;
        // 先左入s1，再右入s1 → 弹出的时候先右后左入s2
        if (p->left_child != NULL)
            s1[++pointer1] = p->left_child;
        if (p->right_child != NULL)
            s1[++pointer1] = p->right_child;
    }
    // 把s2依次弹出打印
    while (pointer2 != -1)
    {
        BiTree p = s2[pointer2--];
        printf("%c ", p->data);
    }
} 
int main(){
    char ch[100] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    BiTree t=Create_Tree(ch);
    InOrder(t);
    printf("\n");
    Search_Child(t,'H');
    Statistics(t);
    printf("高度为 %d\n",TreeHeight(t));
    //先序遍历
    printf("先序遍历为\n");
    PreOrder(t);
    printf("\n");
    //中序遍历
    printf("中序遍历为\n");
    InOrder(t);
    printf("\n");
    //后序遍历
    printf("后序遍历为\n");
    PostOrder(t);
}
