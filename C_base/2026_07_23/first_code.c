#include <stdio.h>
void printa();   //调用函数需要声明
int add(int a,int b);  //函数声明

int main(){
    int sum = 0;

    for(int i=0;i<10;i++){
        sum += i;
    }
    printf("输出为%d\n",sum);

    int i[]={1,2,3,4,5,6,7,8,9,10}; //c里面数组没有默认值，只有垃圾值,只能赋值一次
    printf("%d\n",i[1]);

    int a[][3]={{1,2,3},{3,4,5}}; //二维数组必须指定列数，行数可以不指定,数组越界都不会报错
    printf("%d\n",a[0][0]);

    char t = 'a'; //字符类型只能存储一个字符 (单引号)
    printf("%c\n",t);

    char str[100]="hello world"; //字符串数组必须以\0结尾  (双引号)
    printf("%c\n",str[1]);      //str[]是字符
    printf("%s\n",str);          //str是字符串

    //调用
    printa();
    printf("%d\n",add(1,2));
    
    return 0;
}

void printa(){      //函数在main函数后面定义，必须在main函数前声明
    printf("hello\n");
}

int add(int a,int b){
    return a+b;
}