#include <stdio.h>
#define aa int
#define pi 3.14  //无参宏
#define add(a,b) (a)*(b) //有参宏 因为是简单的字符串替换没有运算规则，所以需要加括号来优先运算
int main(){
    //宏：在源码编译之前替换掉字符串  使用#define来定义 是简单的字符串替换
    //有无参宏 带参宏
    aa c = 3;
    printf("%d\n",c);
    printf("%f\n",pi*2);
    printf("%d",add(1+2,2+3));
    return 0;
}