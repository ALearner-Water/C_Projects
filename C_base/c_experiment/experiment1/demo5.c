#include <stdio.h>
int main()
{
    int x = 0;
    printf("请输入一个int整数：");
    scanf("%d",&x);
    if (x<=0)
    {
        printf("y=%d",x);
    }else if (x>0&&x<10)
    {
        printf("y=%d",5*x-10);
    }else if (x>=10)
    {
        printf("y=%d",10*x-20);
    }
    return 0;
}