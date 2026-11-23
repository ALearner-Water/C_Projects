#ifndef NUM_STACK   // 如果没定义过这个宏
#define NUM_STACK   // 那就定义它（相当于打个标记）
#include <stdbool.h> // 让这个头文件认识 bool
// 声明结构体
typedef float ElmType;

typedef struct stack
{
    struct stack *next;
    ElmType data;
} *Stack, Node;

// 声明函数
Stack Num_init();
void Num_Push(Stack S, ElmType e);
Node *Num_Pop(Stack S);
#endif // 结束
