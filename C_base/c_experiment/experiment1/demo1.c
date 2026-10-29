# include<stdio.h>
int main(){
    int a = 0;
    int b = 0;
    printf("请输入两个int整数：");
    scanf("%d %d",&a,&b);
    if (a>b)
    {
        printf("%d",b);
    }
    else{
        printf("%d",a);
    }
    return 0;
}