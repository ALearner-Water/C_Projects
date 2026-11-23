#ifndef CHAR_STACK // 如果没定义过这个宏
#define CHAR_STACK // 那就定义它（相当于打个标记）
#include <stdbool.h> // 让这个头文件认识 bool
//声明结构体
typedef char ElType;

typedef struct char_stack
{
    struct char_stack *next;
    ElType data;
} *Char_Stack, Char_Node;

//声明函数
Char_Stack Char_init();
void Char_Push(Char_Stack S, ElType e);
Char_Node *Char_Pop(Char_Stack S);
bool Matching(char string[]);
#endif // 结束