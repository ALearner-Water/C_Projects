#include <stdio.h>
int main()
{
    int n = 1;
    int sum = 0;
    do
    {
        sum+=n;
        n++;
    } while (n<=100);
    printf("%d",sum);
    return 0;
}