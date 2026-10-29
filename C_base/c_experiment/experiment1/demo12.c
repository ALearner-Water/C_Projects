#include <stdio.h>
int main(){
    short int s; // range?
    s = 32768;
    printf("%hd %u\n", s, sizeof(short)); // 考虑存储容量及表示范围

    float f;
    double d;
    f = 1.2345678901;
    d = 1.2345678901;
    printf("%.9f %.9f\n", f, d); // 考虑精度

    int si;
    unsigned int ui;
    si = -5;
    ui = 5;
    printf("%d\n", (si > ui)); // 考虑运算导致的类型转换

    char c;
    int i;
    c = 'A';
    i = 0x30;
    printf("%c %d %c\n", c, c, c + 32);
    printf("%d %c %c\n", i, i, i + 6);

    return 0;
}