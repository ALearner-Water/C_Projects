#include <stdio.h>
#include <string.h> //字符串库函数调用的头文件
int main(){
    char str[16]="huangyihan";
    printf("%c\n",str[9]);
    printf("%s\n",str); //直接输出字符串 
    gets(str);  //函数输入字符串   
    puts(str);  //函数输出字符串
    printf("%d\n",sizeof(str)); //字符数组长度
    printf("%d\n",strlen(str)); //字符串长度
    char arr[16];
    strcpy_s(arr,16,str);    //拷贝字符串
    return 0 ;
}