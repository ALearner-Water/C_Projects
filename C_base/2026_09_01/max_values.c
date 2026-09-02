#include <stdio.h>

int max_value(const int arr[], int len){    //const说明数组无法被修改
    int largest=arr[0];
    for(int i=1;i<len;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

int main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={-5,-2,-9};
    int arr3[]={-7};
    int len1=sizeof(arr1)/sizeof(int);
    int len2=sizeof(arr2)/sizeof(int);
    int len3=sizeof(arr3)/sizeof(int);
    printf("max1=%d\n",max_value(arr1,len1));
    printf("max2=%d\n",max_value(arr2,len2));
    printf("max3=%d\n",max_value(arr3,len3));    
    return 0;
}
