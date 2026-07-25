#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,6};
    printf("%p\n",arr);         //数据的首地址为整个数据的地址  00000070aabffd78
    printf("%p\n",&arr[0]);     //00000070aabffd78   +4，一个int类型占4个字节 数据需要加&，数组地址不需要
    printf("%p\n",&arr[1]);     //00000070aabffd7c
    //计算数组长度  数组总字节/单个元素字节
    printf("数组长度为：%d\n",sizeof(arr)/sizeof(arr[0]));

    static int arr1[4][4];        //只有静态数组才会初始化为0，局部数组没有初始化值，里面是随机值
    printf("%p\n",arr1);         //二维数组的首地址为整个数据的地址  00000070aabffd60
    printf("%p\n",&arr1[0][0]);   //00007ff76412d040   +4，一个int类型占4个字节 数据需要加&，数组地址不需要
    printf("%d\n",arr1[0][0]);   //00007ff76412d040

    //for循环遍历二维数组
    for(int i=0;i<4;i++){   //行
        for(int j=0;j<4;j++){   //列
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}