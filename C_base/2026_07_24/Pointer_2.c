#include <stdio.h>
int main(){
    int arr[]={1,2,3,4};
    int *p=arr;
    *p=666;
    *(p++)=555; //先赋值再偏移p,所以arr[0]为555,此时指针指向arr[1]，但是已经提前赋值arr[0]为555
    *(++p)=444; //先偏移再赋值，所以arr[2]为444
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        printf("%d\n",arr[i]);
    }
    
    return 0;
}