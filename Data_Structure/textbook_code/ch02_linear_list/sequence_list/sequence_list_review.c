#include <stdio.h>
#define SEQ_CAPAACITY 8
typedef struct{
    int data[SEQ_CAPAACITY];
    int length;
}SeqList;

int seq_list_insert(SeqList *L,int position,int val){
    if(L==NULL||(L->length)>=SEQ_CAPAACITY||position<1||position>(L->length)+1){
        printf("fill insert");
        return 0;
    }else{
        for (int i = L->length-1; i >=position-1; i--)
        {
            L->data[i+1]=L->data[i];
        }
        L->data[position-1]=val;
        L->length++;
        return 1;
    }
}
int seq_list_find(const SeqList *list, int value){
    if (list==NULL)
    {
        return 0;   
    }
    
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i]==value)
        {
            return i+1;
        }     
    }
    return 0;
}

int seq_list_delete(SeqList *list, int position, int *out_value){
    if (list==NULL||list->length==0||out_value==NULL||position<1||position>list->length)
    {
        return 0;
    }else{
        *out_value=list->data[position-1];
        for (int i = position-1; i <list->length-1; i++)
        {
            list->data[i]=list->data[i+1];
        }
        list->length--;
        return 1;
    }
    
}

int main(void){
    SeqList L={{10,20,30,40},4};
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    seq_list_insert(&L,2,99);
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    SeqList P={{0},0};
    seq_list_insert(&P,1,7);
    printf("%d\n",P.data[0]);
    printf("%d\n",seq_list_find(&L,20));
    printf("%d\n", seq_list_find(&L, 88));
    int val;
    seq_list_delete(&L,3,&val);
    printf("%d,%d",val,L.length);
    return 0;
}