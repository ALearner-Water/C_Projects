#include <stdio.h>
int main()
{
    int a=0;
    do
    {
        printf("请输入一个大于1000的int整数：");
        scanf("%d", &a);
        if (a <= 1000)
        {
            printf("输入数字不满足条件，请重试！\n");
        }
    } while (a <= 1000);

    int res = a - a % 10000 + 1111;
    printf("结果 = %d\n", res);

    return 0;
}