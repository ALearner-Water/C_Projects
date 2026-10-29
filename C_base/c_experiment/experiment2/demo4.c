#include <stdio.h>
int main(){
    int arr[] = {-15, 1024, 12, 60, 19, 26, -18, 19, 100, 86};
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0])-1; i++)
    {
        for (int j = 0; j < (int)sizeof(arr) / sizeof(arr[0]) - 1-i; j++)
        {
            int temp=0;
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
    }
    for (int i = 0; i < (int)sizeof(arr) / sizeof(arr[0]);i++)
    {
        printf("%d\n",arr[i]);
    }
    
    
    return 0;
}