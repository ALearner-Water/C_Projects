//初始化使用动态内存分配进行初始化，返回指针变量，直接调用即可
#include <stdio.h>
#include <stdlib.h>
//顺序表：使用连续的内存单元依次存储相同类型元素
#define MainData 100
typedef int Type;   //int 可以改成任意类型 例如struct book ，叫做高内聚，低耦合

typedef struct{
    Type *data; //这里使用指针后面开辟堆内存空间，不直接使用数组开辟栈空间
    int length;
}seq_list;

//使用动态分配内存初始化
seq_list *initList(){
    seq_list *L=(seq_list*)malloc(sizeof(seq_list));
    L->data = (Type*)malloc(sizeof(Type)*MainData);
    L->length=0;
    return L;
}

//初始化之后需要往顺序表里面添加元素
int append(seq_list *L,Type e){
    if((L->length >= MainData)){
        printf("顺序表已满\n");
        return 0;
    }    
    L->data[L->length]=e;   //insert(&L,L->length+1,e) 也可以直接复用函数
    L->length++;
    return 1;
}

//往顺序表里插入元素
int insert(seq_list *L,int position,Type e){
    //先判断顺序表是否满
    if((L->length) >= MainData){
        printf("数据已满，插入失败\n");
        return 0;
    }else if (position < 1||position > L->length+1) //不能在第一个前面但是可以尾部追加
    {
        printf("插入位置错误，插入失败\n");
        return 0;
    }else{      //此时position <= L->length 
        //循环从后往前遍历
        for(int i=L->length-1;i>=position-1;i--){   //将元素后移
            L->data[i+1]=L->data[i];
        }
        L->data[position-1]=e;
        L->length++;    //插入元素之后长度需要++
        return 1;
    }
    
}

//删除顺序表中元素
int delete(seq_list *L,int position,Type *e){    //*e返回为被删除的数据
    if (L->length==0)
    {
        printf("为空表\n");
        return 0;   
    }else if(position < 1||position > L->length){
        printf("删除位置错误\n");
        return 0;
    }else{
        *e=L->data[position-1]; //得到删除的值
        //实现覆盖，然后长度减1
        for(int i=position-1;i<L->length-1;i++){
            L->data[i]=L->data[i+1];
        }
        L->length--;
        return 1;
    }
}

//在顺序表中查找元素
int research(seq_list *L,Type e){   //返回元素位置
    if(L->length==0){
        printf("顺序表为空\n");
        return 0;
    }else{
        for(int i=0;i<=L->length-1;i++){
            if(e==L->data[i]){
                printf("查找到的元素位置为%d\n",i+1);
                return 1;
            }else{
                printf("没有查找到该元素\n");
                return 0;
            }
        }    
    }
}

//遍历列表，看看是否添加成功 
void traversal(seq_list *L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int main(){
    seq_list *L=initList(); //这里初始化后面调用就不用传地址
    append(L,3);
    append(L,90);
    traversal(L);
    return 0;
}