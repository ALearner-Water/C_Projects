#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    int len;
    ElemType *data; // 使用指针，方便动态分配内存之后扩容
}Seq_list;

Seq_list *initlist(){
    Seq_list *L=(Seq_list*)malloc(sizeof(Seq_list));
    if (L==NULL)
    {
        printf("失败\n");
        return NULL;
    }
    L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if (L->data==NULL)
    {
        printf("失败\n");
        free(L);
        return NULL;
    }
    
    L->len=0;
    return L;
}

void destroy_list(Seq_list *L){
    if (L!=NULL){
        free(L->data);  //先释放数组再释放结构体
        free(L);
    }
}

int append_list(Seq_list *L,ElemType val){
    if(L->len>=MAXSIZE){
        printf("表满");
        return 1;
    }
    L->data[(L->len)]=val;
    L->len++;
    return 0;
}

int delete_list(Seq_list *L,int pos,ElemType *value){
    if(pos<=0||(L->len)<pos){
        printf("位置有误\n");
        return 1;
    }
    else{
        *value = L->data[pos - 1]; // 存值
        for (int i = pos-1; i < (L->len)-1; i++)
        {
            L->data[i]=L->data[i+1];
        }
        L->len--;
    }
    return 0;
}
int insert_list(Seq_list *L,int pos,ElemType val){
    if (L->len>=MAXSIZE)
    {
        printf("表满\n");
        return 1;
    }else if (pos<1||pos>L->len)
    {
        printf("位置错误\n");
        return 1;
    }else{
        for(int i=L->len-1;i>=pos-1;i--){
            L->data[i+1]=L->data[i];
        }
        L->data[pos-1]=val;
        L->len++;
    }
    return 0;
}
int main(){
    Seq_list *L=initlist();
    append_list(L,3);
    append_list(L,4);
    printf("%d\n", L->data[0]);
    insert_list(L,1,9);
    printf("%d,%d,%d",L->data[0],L->data[1],L->data[2]);
}

