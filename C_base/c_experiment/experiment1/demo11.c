#include <stdio.h>
#include <stdlib.h> // rand() 和 srand() 头文件
#include <time.h>   // time() 获取系统时间，用于随机种子

int main(void)
{
    int secret;  // 计算机生成的1~200随机数
    int guess;   // 用户输入猜测的数字
    int count;   // 记录本轮猜的次数
    char choice; // 是否继续下一轮游戏

    // 设置随机种子：用系统当前时间作为种子，保证每次运行随机数不一样
    srand((unsigned int)time(NULL));

    while (1) // 外层循环：可以反复开启多轮猜数字游戏
    {
        // 生成 [1,200] 的随机整数
        // rand()得到0~RAND_MAX的随机整数；rand()%200得到0~199；+1 → 1~200
        secret = rand() % 200 + 1;
        count = 0; // 每一轮游戏，猜测次数清零
        printf("\n==== 新游戏开始！请猜1~200之间的数字，最多猜10次====\n");

        // 内层循环，最多猜10次
        while (count < 10)
        {
            printf("请输入你猜测的数字：");
            scanf("%d", &guess);
            count++; // 每猜一次，次数+1

            if (guess == secret)
            {
                printf("恭喜！猜对了！你一共猜了 %d 次\n", count);
                break; // 猜对，结束本轮猜测
            }
            else if (guess > secret)
            {
                printf("猜大了！还剩 %d 次机会\n", 10 - count);
            }
            else
            {
                printf("猜小了！还剩 %d 次机会\n", 10 - count);
            }
        }

        // 循环结束后判断：10次用完还没猜对
        if (count == 10 && guess != secret)
        {
            printf("10次机会用完，游戏失败！正确数字是：%d\n", secret);
        }

        // 询问用户是否继续玩下一轮
        printf("是否开启下一轮游戏？输入 y继续，其他字符退出：");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {
            printf("游戏结束，欢迎再来！\n");
            break; // 退出外层while循环，整个程序结束
        }
    }
    return 0;
}