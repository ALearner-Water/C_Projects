#include  <stdio.h>
int main(){
    char a[] = "hello";
    char b[] = "world";
    char c[100]; // 存放拼接后的结果，空间要足够大
    int i = 0, j = 0;

    // 第一步：复制 a 到 c
    while (a[i] != '\0')
    {
        c[i] = a[i];
        i++;
    }
    // 此时 i 停在a的'\0'位置，从这里接b
    while (b[j] != '\0')
    {
        c[i] = b[j];
        i++;
        j++;
    }
    c[i] = '\0'; // 手动加上字符串结束标记！非常关键

    printf("拼接结果：%s\n", c);
    return 0;
}