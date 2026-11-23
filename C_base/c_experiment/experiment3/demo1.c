#include <stdio.h>

//设置结构体
typedef struct Date
{
    int year;
    int month;
    int day;
}Date;

//求day函数
int days(Date date){
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    int year=date.year;
    //先累加
    for (int i = 0; i <date.month-1; i++)
    {
        sum+=m[i];
    }
    //是闰年+1
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        if (date.month>2)
        {
            sum++;
        }
    }
    //最后加day
    sum+=date.day;
    return sum;
}

//主函数
int main(){
    Date date={2020,12,31};
    int d=days(date);
    printf("该日为今年的第%d天\n",d);
    return 0;
}