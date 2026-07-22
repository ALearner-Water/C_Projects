#include <stdio.h>
#include <stdlib.h>
int main(){
    /*  头文件为 stdlic.h 内存分配  
    malloc()    参数：申请的内存空间大小，字节为单位  内存连续  需要手动初始化
    calloc()    参数：申请的内存空间个数，申请的内存空间大小，字节为单位  内存连续 默认初始化为0
    realloc()   修改申请的内存空间大小，字节为单位  内存连续  需要手动初始化    参数：原来的内存空间指针，申请的内存空间大小，字节为单位
    free()      释放内存
    */
    //void *p = malloc(sizeof(int)*7);      //返回值为 void*类型，可以强转 叫申请内存空间
    int *p= (int*)malloc(sizeof(int)*10);    //c默认隐式转换
    //给内存空间初始化
    for (int i= 0; i < 10; i++){
        * (p + i)=i;   //p为int类型，所以加1左移4，(指针的偏移)
    }
    for(int i=0;i<10;i++){
        printf("%d\n",*(p + i));
    }

    printf("-----------------------\n");
    int *a=calloc(10,sizeof(int));   //calloc() 申请10个int类型的内存空间，默认初始化为0
    for(int i=0;i<10;i++){
        printf("%d\n",*(a + i));
    }
    printf("------------------------\n");
    int *q=realloc(a, sizeof(int)*20);   //重新申请内存空间，原来的内存空间指针，申请的内存空间大小，字节为单位

    for (int i = 10; i < 20; i++)
    {
        *(q + i) = 0;   //p为int类型，所以加1左移4，(指针的偏移)
    }
    
    for(int i=0;i<20;i++){
        printf("%d\n",*(q + i));
    }
    //最后要释放内存
    free(p);
    free(q);    
    
    return 0;
}