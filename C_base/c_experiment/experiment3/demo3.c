#include <stdio.h>

void Sort(int *arr,int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (*(arr+j)>*(arr+j+1))
            {
                int k=*(arr+j);
                *(arr+j) = *(arr + j + 1);
                *(arr + j + 1) = k;
            }
        }
    }
    
}

int main(){
    printf("输入四个整数\n");
    int a,b,c,d;
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    int arr[4]={a,b,c,d};
    Sort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("排序结果如下：\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ",*(arr+i));
    }
    return 0;
}