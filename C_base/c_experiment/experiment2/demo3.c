#include <stdio.h>
#include <math.h>

int cul(int n){
    int sum=0;
    n=2;
    for (int i = 1; i < 11; i++)
    {
     int middle=pow(n,i);
     sum+=middle;  
    }
    return sum;
}
int main()
{
    int sum=cul(2);
    printf("%d",sum);
    return 0;
}