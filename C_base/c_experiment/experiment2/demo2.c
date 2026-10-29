#include <stdio.h>
#include <math.h>
int istriangle (float a,float b,float c){
    float max=a;
    if (b>a)
    {
        max=b;
    }else if (c>a)
    {
        max=c;
    }
    float sum=a+b+c-max;
    if (sum>max)
    {
        return 1;
    }else{
        return 0;
    }
}

float cularea(float a,float b,float c){
    float s=(a+b+c)/2;
    float area=sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

int main()
{
    float a, b, c;
    printf("请输入三角形三边a,b,c：");
    scanf("%f %f %f", &a, &b, &c);

    if (istriangle(a, b, c))
    {
        float area = cularea(a, b, c);
        printf("三角形面积 = %.2f\n", area);
    }
    else
    {
        printf("错误：不能构成三角形！\n");
    }
    return 0;
}