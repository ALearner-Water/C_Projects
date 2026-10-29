#include <stdio.h>

void num_to_str(int n){
    if (n<0)
    {
        //负数先变为正数
        printf("-");
        n=-n;
    }
    if (n>0)
    {
        //不断取余保存结果然后继续递归
        int str=n%10;
        n=n/10;
        num_to_str(n);
        printf("%d",str);
    }
}

int main(){
    printf("请输入任意位数整数");
    int n=0;        
    scanf("%d",&n);
    num_to_str(n);
    return 0;
}