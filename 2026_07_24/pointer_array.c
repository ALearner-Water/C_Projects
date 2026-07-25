#include <stdio.h>
int main(){
    //指针数组是一个数组，里面存的是地址，可以用二级指针来使用,方便操作数据
    int arr1[]={1,2,3,4,5};
    int arr2[]={6,7,8,9};
    int arr3[]={10,11};
    int* p[]={arr1,arr2,arr3};  //相当于二维数组
    int **q=p;  //二级指针可以指向一级指针
    /*printf("%p\n",arr1);    //arr1的内存地址
    printf("%p\n",&arr1);
    printf("%p\n",p[0]);    //p[0]也就是arr1的内存地址
    printf("%p\n",p);       //开辟出来存储{}里面的内存地址
    printf("%p\n",*q);       //解引用也就是arr1的内存地址
    printf("%p\n",q);       //q与p相等
    printf("%d\n",**q);     //解引用两次，就是arr[0]=1
    printf("%d\n",*p);      //把arr[1]的内存地址当作值打印
    printf("%d\n",*arr1);   //等价于arr[0]*/
    //c没有求长度的函数只能自己写
    int count[]={sizeof(arr1)/sizeof(int),sizeof(arr2)/sizeof(int),sizeof(arr3)/sizeof(int)};
    for(int i=0;i<3;i++){
        for(int j=0;j<count[i];j++){
            printf("%d ",**q+j);
        }
        q++;
    }
    return 0;
}