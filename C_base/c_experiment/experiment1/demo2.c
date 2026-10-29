#include <stdio.h>
int main()
{
    int a = 0;
    float b = 0.0;
    printf("请输入一个int整数：");
    scanf("%d",&a);
    printf("请输入一个float浮点数：");
    scanf("%f",&b);
    if (a > b)
    {
        printf("%d", a);
    }
    else
    {
        printf("%.2f", b);
    }
    return 0;
}