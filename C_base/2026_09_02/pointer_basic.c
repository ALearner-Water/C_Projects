#include <stdio.h>
int main()
{
    int x = 10;
    int *p = &x;    //将x的地址赋给p指针
    printf("x=%d\n", x);   
    printf("&x=%p\n", &x);  
    printf("p=%p\n", p);    //打印p的内容需要用%p，因为里面是地址
    printf("*p=%d\n", *p);  //*p解引用
    printf("&p=%p\n", &p);  //打印地址使用%p
    printf("%d\n", p == &x);
    *p = 20;        //将p指向的值进行一个改变
    printf("x=%d\n", x);
    return 0;
}
