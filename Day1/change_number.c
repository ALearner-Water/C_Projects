#include <stdio.h>
void changenumber(int *a,int *b);
int main(){
    int a=10;
    int b=20;
    printf("交换前为%d,%d\n",a,b);
    changenumber(&a,&b);
    printf("交换后为%d,%d",a,b);
    return 0;
}
void changenumber(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}