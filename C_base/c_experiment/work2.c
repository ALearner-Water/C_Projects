#include <stdio.h>
int main(){
    //分上下两半打印
    int n=0;
    char c='*';
    printf("请输入距离：");
    scanf("%d",&n);
    printf("请输入符号：");
    scanf(" %c",&c);        //前面加空格，吃掉缓冲区的回车
    
    //上半
    for (int i = 0; i <n; i++)
    {
        //空格
        for (int j = 0; j < n-i; j++)
        {
            printf(" ");
        }
        //符号
        for (int k = 0; k < 2*i+1; k++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
    
    //下半
    for (int i = n-2; i >= 0; i--)
    {
        //空格
        for (int j = 0; j < n-i; j++)
        {
            printf(" ");
        }
        //符号
        for (int k = 0; k < 2*i+1; k++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
    
    return 0;
}