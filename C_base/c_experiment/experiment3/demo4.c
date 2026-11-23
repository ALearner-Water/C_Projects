#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // 动态分配300个int空间，用指针接收（动态存储）
    int *p_month = (int *)malloc(300 * sizeof(int));
    if (p_month == NULL) // 一定要判断内存是否分配失败
    {
        printf("内存分配失败！\n");
        return -1;
    }

    int count[12] = {0};             // count[0]对应1月，count[1]对应2月 ... count[11]对应12月
    srand((unsigned int)time(NULL)); // 设置随机种子

    // 循环生成300个1~12的随机月份，存入动态内存
    for (int i = 0; i < 300; i++)
    {
        // 生成 1~12
        *(p_month + i) = rand() % 12 + 1;
        int month = *(p_month + i);
        count[month - 1]++;
    }

    printf("===== 各月出生率统计（总人数：300）=====\n");
    for (int i = 0; i < 12; i++)
    {
        float rate = count[i] / 300.0f;
        printf("第%d月：人数=%d，出生率=%.2f%%\n", i + 1, count[i], rate * 100);
    }

    // 释放动态内存
    free(p_month);
    p_month = NULL;

    return 0;
}
