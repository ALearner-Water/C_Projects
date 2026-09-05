#include <stdio.h>
#include <stdlib.h>
#define MAXSIDE 100
typedef int ElemType;
typedef struct {
    ElemType *data;     //不知道data空间多大需要初始化的时候动态分配
    int length;
}Seq_list;

Seq_list* initList(){
    Seq_list *L=(Seq_list*)malloc(sizeof(Seq_list));    //先申请结构体指针的内存
    L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIDE) //再动态动态分配data的内存
    L->length=0;
    return L;   //最后初始化完成之后返回L
}

void appendList(Seq_list *L,ElemType val){
    while ((L->length)>=MAXSIDE){
        printf("顺序表已满");    
    }
    L->data[L->length]=val;
    L->length++;
}
void listElem(Seq_list *L){
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ",L->data);
    }
    printf("\n");
}
void insertElem(Seq_list *L,int pos,ElemType val){
    if ((L->length) >= MAXSIDE)
    {
        printf("顺序表已满");
    }
    if (pos<0||pos>(L->length))
    {
        printf("插入位置无效");
    }
    for (int i = (L->length)-1; i>pos-1; i++)
    {
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=val;
    L->length++;
}
void deleteElem(Seq_list *L,int pos,ElemType *val){ //val使可以接收到被删除的值
    *val=L->data[pos-1];
    for(int i=pos-1;i<L->length-1;i++){
        L->data[i]=L->data[i+1];
    }
    L->length--;
}
int main(){
    Seq_list L;
    initList(&L);
    return 0;
}