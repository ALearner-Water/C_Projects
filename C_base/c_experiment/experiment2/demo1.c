#include <stdio.h>
#include <string.h>

int main(void)
{
    // 平行数组：直接内置10个学生的成绩，无需手动输入
    char id[10][20] = {
        "001", "002", "003", "004", "005",
        "006", "007", "008", "009", "010"};
    float mt[10] = {78, 92, 85, 69, 95, 76, 88, 82, 90, 73}; // 数学
    float en[10] = {85, 88, 79, 92, 76, 90, 84, 77, 91, 81}; // 英语
    float ph[10] = {90, 85, 92, 78, 88, 82, 95, 76, 89, 74}; // 物理
    float total[10], avg[10];

    int n = 10; // 固定10个学生

    // 1. 自动计算总分、平均分
    for (int i = 0; i < n; i++)
    {
        total[i] = mt[i] + en[i] + ph[i];
        avg[i] = total[i] / 3.0f;
    }

    // 2. 冒泡排序：按总分从高到低，同步交换所有数组
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (total[j] < total[j + 1])
            {
                // 交换总分
                float t_total = total[j];
                total[j] = total[j + 1];
                total[j + 1] = t_total;
                // 交换平均分
                float t_avg = avg[j];
                avg[j] = avg[j + 1];
                avg[j + 1] = t_avg;
                // 交换数学
                float t_mt = mt[j];
                mt[j] = mt[j + 1];
                mt[j + 1] = t_mt;
                // 交换英语
                float t_en = en[j];
                en[j] = en[j + 1];
                en[j + 1] = t_en;
                // 交换物理
                float t_ph = ph[j];
                ph[j] = ph[j + 1];
                ph[j + 1] = t_ph;
                // 交换学号
                char t_id[20];      //创建一个临时盒子
                strcpy(t_id, id[j]);    //将j存进去
                strcpy(id[j], id[j + 1]);   //再将j+1存到j里面
                strcpy(id[j + 1], t_id);    //最后将盒子里面的值存到j+1完成交换
            }
        }
    }

    // 3. 打印成绩名次表
    printf("==================== 成绩名次表 ====================\n");
    printf("%s%s%s%s%s%s%s\n",
           "\t名次", "  学生编号", "\t数学MT", "\t英语EN", "\t物理PH", "\t 总分", "\t平均分");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
               i + 1, id[i], mt[i], en[i], ph[i], total[i], avg[i]);
    }

    //查询学号 
    printf("请输入学号:");
    char search_id[20];
    scanf("%s",search_id);   //数组已经是地址不需要&
    int find_flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(id[i], search_id) == 0)  //字符串是否匹配
        {
            printf("学生编号：%s\n", id[i]);
            printf("班级排名：第%d名\n", i + 1);
            printf("数学：%.1f  英语：%.1f  物理：%.1f\n", mt[i], en[i], ph[i]);
            printf("总分：%.1f  平均分：%.1f\n", total[i], avg[i]);
            find_flag= 1;
            break;
        }
     }
     if (!find_flag)
         printf("未找到该学号学生！\n");
    return 0;
}