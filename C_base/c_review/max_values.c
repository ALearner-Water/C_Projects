#include <stdio.h>
int largest(int arr[],int len){
    int max=arr[0];
    for(int i=1;i<len;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int arr[]={-1,22,5,0,33,-7};
    int len=sizeof(arr)/sizeof(int);
    int max=largest(arr,len);
    printf("%d",max);
    return 0;
}