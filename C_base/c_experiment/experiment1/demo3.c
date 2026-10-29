#include <stdio.h>
int main()
{
    float C = 0.0;
    float F = 0.0;
    printf("请输入摄氏温度：");
    scanf("%f", &C);
    F = C * 9.0 / 5.0 + 32;
    printf("%.2f",F);
    return 0;
}