#include <stdio.h>

int main()
{
    int year, month, day;
    int sum = 0;
    // 每个月的天数，下标0不用，1~12对应1~12月
    int mon_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("input year: ");
    scanf("%d", &year);
    printf("input month: ");
    scanf("%d", &month);
    printf("input day: ");
    scanf("%d", &day);

    // 累加前面所有月份
    for (int i = 1; i < month; i++)
    {
        sum += mon_days[i];
    }
    // 加上当月日期
    sum += day;

    // 判断闰年，并且月份大于2才需要+1（2月及之前不受影响）
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        if (month > 2)
        {
            sum += 1;
        }
    }

    printf("这是该年的第 %d 天\n", sum);
    return 0;
}
