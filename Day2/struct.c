#include <stdio.h>
int main(){
    struct point{
        int x;
        int y;
    };
    struct point i={1,2};
    i.x=3;
    i.y=4;
    printf("%d,%d",i.x,i.y);
    return 0;
}