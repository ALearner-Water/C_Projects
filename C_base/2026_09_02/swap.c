#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;  //*a解引用：取出a指向的外部变量x的值，保存到临时变量temp
    *a = *b;        //*b读取b指向的y的值；*a写入，把该值存入a指向的x内存空间
    *b = temp;      // 将temp保存的原值，写入b指向的y内存空间
}
int main(){
    int x = 3;
    int y = 8;
    swap(&x,&y);
    printf("%d,%d",x,y);
    return 0;
}