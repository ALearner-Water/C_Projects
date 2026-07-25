#include <stdio.h>
typedef struct point{
    int x;
    int y;
}PO;
struct point pointer (int a,int b){
    PO xy;
    xy.x=a;
    xy.y=b;
    return xy;
}
int main(){
    int a,b;
    scanf("%d,%d",&a,&b);
    PO cc=pointer(a,b);
    printf("%d,%d",cc.x,cc.y);
    return 0;
}