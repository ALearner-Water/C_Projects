#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hf_tree
{
    int weight;
    int parent,lchild,rchild;
}hf_node,*hf_tree;

//找两个没有父亲且权最小的节点 n为总节点个数
void Select(hf_tree HT,int *s1,int *s2,int n){
    if (n==0)
    {
        return;
    }
    int min1=-1;
    int min2=-1;    //下标
    for (int i = 0; i < n; i++)
    {
        //无父亲才行
        if (HT[i].parent==0)
        {
            if (min1==-1||HT[i].weight<HT[min1].weight)
            {
                //若出现比min1小的，就将min1的变成第二小，然后把i的值给min1
                min2=min1;
                min1=i;
            }else if(min2==-1||HT[i].weight<=HT[min2].weight){
                min2=i;
            }  
        }
    }
    //输出两个节点
    *s1=min1;
    *s2=min2;
}

//构建哈夫曼树
hf_tree Create_HF_Tree(int w[],int n){  //n不能在函数里面算出来，现在的w是数组首地址    在main是真数组
    hf_tree HT=(hf_tree)malloc((2*n-1)*sizeof(hf_node));
    //构建叶子节点
    for (int i = 0; i < n; i++)
    {
        HT[i].weight=w[i];
        HT[i].parent = 0;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }
    //挑选节点去合并
    for (int k = n; k<2*n-1; k++)
    {
        //新节点初始化
        HT[k].parent = 0;
        HT[k].lchild = -1;
        HT[k].rchild = -1;
        //挑选最小权值
        int s1,s2;
        Select(HT,&s1,&s2,k);
        //将新生成的节点放入HT
        HT[k].lchild=s1;
        HT[k].rchild=s2;
        HT[s1].parent=k;
        HT[s2].parent=k;
        HT[k].weight=HT[s1].weight+HT[s2].weight;
    }
    return HT;
}

//生成编码
void HF_EnCode(hf_tree HT,int n,char **ch){
    //反向遍历后面再反转
    char b[100];    //存一个编码
    int now;    //当前下标
    int par;    //父节点下标
    int len;    //编码长度
    for (int i = 0; i < n; i++)
    {
        now=i;
        par=HT[i].parent;
        len=0;  //重置
        //一直找父节点
        while (par!=0)
        {
            //左0右1
            if (HT[par].lchild==now)
            {
                b[len++]='0';
            }else if (HT[par].rchild==now)
            {
                b[len++]='1';
            }
            //继续往上
            now=par;
            par=HT[now].parent;   
        }
        // 加结束标记
        b[len] = '\0';
        // 得到编码后反转
        //倒着遍历
        char code[100];
        int k=0;
        for (int j = len-1; j >=0 ; j--)
        {
            code[k++]=b[j];
        }
        code[k]='\0';
        //申请新内存将编码存入
        ch[i]=(char*)malloc(len+1);
        strcpy(ch[i],code);
    }

}

void HF_DeCode(char *code,hf_tree HT,int m,char *decode){
    //先找到根节点从根节点往后遍历
    int root;
    for (int i = 0; i < m; i++)
    {
        if (HT[i].parent==0)
        {
            root=i;
            break;
        }
    }
    int p=root;
    for (int j = 0; code[j]!='\0'; j++)
    {
        //往左走
        if (code[j]=='0')
        {
            p=HT[p].lchild;
        }
        //往右走
        else if (code[j]=='1')
        {
            p=HT[p].rchild;
        }
        //找到了
        if (HT[p].lchild==-1&&HT[p].rchild==-1)
        {
            //查表输出字符
            printf("%c",decode[p]);
            p=root;
        }
        
    }   
}

// 辅助函数：根据字符c，在sym里找到下标p
int findSymIndex(char c, char sym[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (sym[i] == c)
            return i;
    }
    return -1;
}

//找到字符对应的下标
int main(){
    // 构建字符表
    char text[] = "The Chinese official said he viewed the Trump Presidency not as an aberration but as the product of a failing political system. This jibes with other accounts. The Chinese leadership believes that the United States, and Western democracies in general, haven't risen to the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure.";
    int count[256] = {0}; // ASCII 0~255，统计每个字符出现次数
    // 遍历原文统计
    for (int i = 0; text[i] != '\0'; i++)
    {
        count[(unsigned char)text[i]]++;
    }

    //字符表
    char sym[256];
    //权值
    int weight[256];
    int k = 0; // n：不同字符的总数（叶子数量）
    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0) // 这个字符出现过
        {
            sym[k] = (char)i;
            weight[k] = count[i];
            k++;
        }
    }

    //建树
    hf_tree HT=Create_HF_Tree(weight,k);
    char **ch = (char **)malloc(k* sizeof(char *));
    HF_EnCode(HT,k,ch);
    for (int i = 0; i < k; i++)
    {
        printf("字符 %c 编码 %s\n",sym[i],ch[i]);
    }

    // 把原文全部编码
    char code_buf[10000] = {0}; // 存全部拼接后的01
    for (int i = 0; text[i] != '\0'; i++)
    {
        int idx = findSymIndex(text[i], sym, k);
        strcat(code_buf, ch[idx]);
    }
    printf("\n原始文本对应的01编码串\n");
    printf("%s\n", code_buf);
    printf(" 译码还原结果\n");
    HF_DeCode(code_buf, HT, 2*k- 1, sym);
    return 0;
}