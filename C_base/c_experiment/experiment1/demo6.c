#include <stdio.h>
int main()
{
    int n;
    int qian, bai, shi, ge;
    printf("请输入不多于4位的正整数：");
    scanf("%d", &n);

    qian = n / 1000;
    bai = n / 100 % 10;
    shi = n / 10 % 10;
    ge = n % 10;

    int count; // 保存位数
    if (n >= 1000)
    {
        count = 4;
        printf("这是4位数\n");
        printf("千位：%d，百位：%d，十位：%d，个位：%d\n", qian, bai, shi, ge);
        printf("逆序：%d%d%d%d\n", ge, shi, bai, qian);
    }
    else if (n >= 100)
    {
        count = 3;
        printf("这是3位数\n");
        printf("百位：%d，十位：%d，个位：%d\n", bai, shi, ge);
        printf("逆序：%d%d%d\n", ge, shi, bai);
    }
    else if (n >= 10)
    {
        count = 2;
        printf("这是2位数\n");
        printf("十位：%d，个位：%d\n", shi, ge);
        printf("逆序：%d%d\n", ge, shi);
    }
    else
    {
        count = 1;
        printf("这是1位数\n");
        printf("个位：%d\n", ge);
        printf("逆序：%d\n", ge);
    }
    return 0;
}