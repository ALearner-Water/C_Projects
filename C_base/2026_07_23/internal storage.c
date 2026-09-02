//用&来取地址
#include <stdio.h>
int main(){
    int a = 10;
    printf("a的地址为%p\n",&a); //%p打印地址 ,取地址需要&
    
    printf("a的值为%p\n",a); //会把10当作内存打印出来 00000033e47ff8ec（随机）
    
    return 0;
}