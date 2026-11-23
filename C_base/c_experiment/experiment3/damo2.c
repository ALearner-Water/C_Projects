#include <stdio.h>

typedef struct Student
{
    char number[20];
    char name[20];
    float China;
    float Math;
    float English;
    float avg;
}Student;

int main(){
    //10个学生
    Student stu[10];
    for (int i = 0; i < 10; i++)
    {
        printf("请输入第%d个学生：学号 姓名 语文 数学 英语\n", i + 1);
        scanf("%s %s %f %f %f", stu[i].number, stu[i].name, &stu[i].China, &stu[i].Math, &stu[i].English);
        //计算平均分
        stu[i].avg=(stu[i].China+stu[i].Math+stu[i].English)/3.0;
    }
    //冒泡排序
    for (int i = 0; i < 10-1; i++)
    {
        for (int j = 0; j < 10-i-1; j++)
        {
            if (stu[j].avg<stu[j+1].avg)
            {
                Student s=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=s;
            }
        }
    }
    //输出总表
    printf("\n成绩表\n");
    printf("学号\t姓名\t语文\t数学\t英语\t平均分\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.2f\n",
               stu[i].number, stu[i].name, stu[i].China, stu[i].Math, stu[i].English, stu[i].avg);
    }
    //输出前三
    printf("\n平均分前三名\n");
    for (int i = 0; i < 3; i++)
    {
        printf("第%d名：%s，平均分：%.2f\n", i + 1, stu[i].name, stu[i].avg);
    }
    return 0;
}