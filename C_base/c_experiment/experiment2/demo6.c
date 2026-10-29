#include <stdio.h>
int culmul(int n){
    if (n==1||n==0)
    {
        return 1;
    }else{
        return n*culmul(n-1);
    }
    
}
int main(){
    int n,m;
    printf("请输入m，n\n");
    scanf("%d,%d",&m,&n);
    if (n < 0 || m < 0 || m > n)
    {
        printf("输入不合法！\n");
        return 0;
    }
    float sum=(float)culmul(n)/(float)(culmul(n-m)*culmul(m));
    printf("%.1f",sum);
}