#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Char_Stack.h"
#include "Num_Stack.h"
#include <ctype.h>
#include <time.h>

//判断优先级函数
int operator_priority(char op){
    if (op=='+'||op=='-')
    {
        return 1;
    }else if (op=='*'||op=='/')
    {
        return 2;
    }else{
        return 0;
    }
}

//做运算，后续直接复用
float calculate_once(Stack num_stack, Char_Stack op_stack){
    //首先弹出两个数再弹出一个操作数 注意先后
    Node *num_1=Num_Pop(num_stack);
    Node *num_2=Num_Pop(num_stack);
    Char_Node *op=Char_Pop(op_stack);
    float res=0.0;
    // if else判断op
    if (op->data == '+')
    {
        res = num_2->data + num_1->data;
    }
    else if (op->data == '-')
    {
        res = num_2->data - num_1->data;
    }
    else if (op->data == '*')
    {
        res = num_2->data * num_1->data;
    }
    else if (op->data == '/')
    {
        res = num_2->data / num_1->data;
    }
    free(num_1);
    free(num_2);
    free(op);
    return res;
}

void Culculate(char string[],float *r){
    //创建数据栈和链栈
    Stack Num_S = Num_init();
    Char_Stack Op_s = Char_init();
    int len=strlen(string);
    float e =0.0;   //放连接数
    //先看看表达式是否正确
    if (Matching(string))
    {
        for (int i = 0; i < len; i++)
        {
            //判断是数字还是运算符 + - * /  ()
            if (!isdigit(string[i]))    //不是数字则再判断
            {
                // 是op判断优先级 决定是否需要先计算再存数
                // 左括号直接入栈
                if (string[i]=='(')
                {
                Char_Push(Op_s,string[i]);
                }else if(string[i]==')')
                {
                    while (Op_s->next != NULL && Op_s->next->data != '(')
                    {
                        // 遇到右括号就一直运算直到遇到左括号
                        float res = calculate_once(Num_S, Op_s);
                        Num_Push(Num_S,res);
                    }
                    //运算完将左括号也pop
                    Char_Node *node = Char_Pop(Op_s);
                    free(node);
                }
                else // 计算优先级，视情况先计算再入栈
                {
                    //栈是否为空且是否碰到左括号，然后再判断优先级看是先算栈里面的还是直接入栈
                    while (Op_s->next != NULL && Op_s->next->data != '(' && operator_priority(Op_s->next->data) >= operator_priority(string[i]))
                    {
                        float res = calculate_once(Num_S, Op_s);
                        Num_Push(Num_S, res);
                    }
                    Char_Push(Op_s, string[i]);
                }
            }else{      //否则就是数字  对数字进行处理再把入栈
                //拼接数字若下一个数还是数字就继续拼接
                    e=e*10.0+(string[i]-'0');
                    if(!isdigit(string[i+1])){
                        // 否则就入栈
                        Num_Push(Num_S, e);
                        // 入栈后重置e
                        e = 0.0;
                    }
                }
            }
        
    }else
    {
        printf("表达式错误");
        return;
    }
    //最后都判断完若栈内还有元素就继续运算
    while (Op_s->next != NULL)
    {
        float res = calculate_once(Num_S, Op_s);
        Num_Push(Num_S, res);
    }
    // 最后返回结果
    Node *result_node = Num_Pop(Num_S);
    if (result_node == NULL)
    {
        return;
    }
    *r = result_node->data;
    //释放掉空节点
    free(result_node);
    free(Num_S);
    free(Op_s);
}
int main(){
    Char_Stack S=Char_init();
    // 设置随机种子
    srand((unsigned)time(NULL));
    //生成随机数
    for (int i = 0; i < 10; i++)
    {
        int random=100+rand()%900;
        Char_Push(S,random);       //入栈
    }
    //出栈
    for (int i = 0; i < 10; i++)
    {
        Char_Pop(S);
    }
    char string[20]="((3+3)*2)-3";
    float res = 0.0f;
    Culculate(string,&res);
    printf("%.2f", res);
}
