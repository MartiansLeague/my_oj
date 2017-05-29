#include"malloc.h" /* malloc()等 */
#include"stdio.h"
#include"stdlib.h"

typedef int ElemType;
typedef struct /*静态查找表的顺序存储结构 */
{
    ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */
    int length; /* 表长度 */
} SSTable;

void Creat_Seq(SSTable &ST,int n)
{
    /* 操作结果: 构造一个含n个数据元素的静态顺序查找表ST(数据来自数组r) */
    int i,temp;
    ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* 动态生成n个数据元素空间(0号单元不用) */
    if(!(ST).elem)
    {
        printf("ERROR\n");
        exit(0);
    } /*内存分配失败结束程序*/
    for(i=1; i<=n; i++)
    {
        scanf("%d",&temp);
        *(ST.elem+i)=temp; /* 依次赋值给ST */
    }
    ST.length=n;
}

int Search_bin(SSTable &ST,ElemType key)
{
    /* 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为 */
    /* 该元素在表中的位置，否则为0。算法9.1 */

    int l,r,mid;

    l=1;
    r=ST.length;
    mid=(r+l)/2;

    while(l<=r)
    {
        //  printf("%d%d%d\n",l,mid,r);

        if(ST.elem[mid]==key)
        {
            return mid;
        }
        if(key>ST.elem[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(r+l)/2;
    }

    // printf("%d%d%d",ST.elem[r],r,key);

    return 0;

}



main()
{
    SSTable ST;
    int loc,key;
    int n;
    scanf("%d",&n);
    Creat_Seq(ST,n);
    //printf("Please input the key value：");
    scanf("%d",&key);
    loc = Search_bin(ST,key);
    if(loc!=0)
        printf("The element position is %d.\n",loc-1);
    else
        printf("The element is not exist.\n");
}
