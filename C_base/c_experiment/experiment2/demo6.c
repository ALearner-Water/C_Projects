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
    printf("%.1f\n",sum);
    float c58 = (float)culmul(8) / (float)(culmul(8 - 5) * culmul(5));
    float c25 = (float)culmul(5) / (float)(culmul(5 - 2) * culmul(2));
    float c07 = (float)culmul(7) / (float)(culmul(7 - 0) * culmul(0));
    printf("c58=%.1f\n",c58);
    printf("c25=%.1f\n",c25);
    printf("c07=%.2f\n",c07);
}