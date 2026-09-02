#include <stdio.h>
int *aaa();
int main(){
    /*野指针：(需要避免)  指针默认空值为null int *p=Null；
    1. 指针没有初始化
    2. 指针指向的内存空间被释放
    3.指针越界访问
    */

   // 1
    int *p;
    int a=10;

    // 2 
    printf("--------------\n");
    int *b = aaa(); //q所指向的内存已经被释放
    printf("%p",*b);

    // 3

    return 0;
}

int * aaa(){
    int b=20;
    int *q=&b;
    return q;   //返回的是指针不能是*q
}