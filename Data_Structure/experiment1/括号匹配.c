#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef char ElType;

typedef struct char_stack
{
    struct char_stack *next;
    ElType data;
} *Char_Stack, Char_Node;



// 初始化 带头节点
Char_Stack Char_init()
{
    Char_Stack s = (Char_Node *)malloc(sizeof(Char_Node));
    if (s == NULL)
    {
        return NULL;
    }
    s->next = NULL;
    return s;
}

// 入栈
void Char_Push(Char_Stack S, ElType e)
{
    // 新建节点
    Char_Node *node = (Char_Node *)malloc(sizeof(Char_Node));
    if (node == NULL)
    {
        return;
    }
    node->data = e;
    node->next = S->next;
    S->next = node;
}

// 出栈
Char_Node *Char_Pop(Char_Stack S)
{
    if (S->next == NULL)
    {
        return NULL;
    }
    // 拿到栈顶指针
    Char_Node *n = S->next;
    // 移动栈顶指针
    S->next = n->next;
    return n;
}

// 判断括号匹配问题
bool Matching(char string[])
{
    int len = strlen(string);
    // 左括号入栈遇到右括号出栈匹配，失败false正确false 遇到非字符自动跳过 continue
    Char_Stack S = Char_init();
    for (int i = 0; i < len; i++)
    {
        // 左括号
        if (string[i] == '{' || string[i] == '[' || string[i] == '(')
        {
            Char_Push(S, string[i]);
        }
        else
        {
            // 非括号跳过
            if (string[i] != '}' && string[i] != ']' && string[i] != ')')
            {
                continue;
            }
            // 遇到右括号出栈
            Char_Node *p = Char_Pop(S);
            // 栈内若没有元素直接退出
            if (p == NULL)
            {
                return false;
            }
            if ((string[i] == '}' && p->data == '{') || (string[i] == ']' && p->data == '[') || (string[i] == ')' && p->data == '('))
            {
                // 用完释放节点
                free(p);
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    // 看栈还有没有残留
    if (S->next != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main(){
    char a[]="[({})]";
    bool b=Matching(a);
    printf("%d",b);
}