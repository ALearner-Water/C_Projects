#include <stdio.h>
//结构体是一个结构类型 ，写在main函数外面则全局都可以使用，若写在main函数里面则只有main里面可以用
//结构数组是一个数组，里面的元素是一样的数据类型，类似Arraylist<student>
    struct point{
        int x;
        int y;  //存放数据的描述，然后依次初始化
    };  //结尾要加分号
    //可以使用typedef进行重定义
    typedef struct point sp;    //以后就不用写struct

    typedef struct HurtPoint{   //也可以直接在结构体定义的时候直接定义
        int x;
        int y;
    }HP;
    
int main(){
    struct point i={1,2};   //初始化处理
    sp s={3,4}; //可以直接定义
    s.x=5;
    i.x=3;  //可以修改
    i.y=4;
    HP hp={1.2,3.4};    //也可以直接定义
    HP h1[3]={{1,2},{2,3},{3,4}};   
    printf("%d\n",h1[0].x); 
    printf("%d,%d",i.x,i.y);
    return 0;
}