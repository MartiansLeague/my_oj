#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)    // �㷨6.4
{
    // �������������������н���ֵ��һ���ַ�������#���ַ���ʾ������
    // �������������ʾ�Ķ�����T��
    char ch;
    scanf("%c",&ch);
    if (ch=='#') T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        T->data=ch; // ���ɸ����
        CreateBiTree(T->lchild)  ;  // ����������
        CreateBiTree(T->rchild)  ;   // ����������
    }
    return OK;
} // CreateBiTree


Status PrintElement( ElemType e )    // ���Ԫ��e��ֵ
{
    printf("%c", e );
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // ǰ�����������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����

    if(T)
    {

        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit))
                    return OK;
        return ERROR;


    }
    return OK;

} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����

    if(T)
    {
        if(InOrderTraverse(T->lchild,Visit))
            if(Visit(T->data))

                if(InOrderTraverse(T->rchild,Visit))
                    return OK;
        return ERROR;


    }
    return OK;



} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����
    if(T)
    {
        if(PostOrderTraverse(T->lchild,Visit))
             if(PostOrderTraverse(T->rchild,Visit))
            if(Visit(T->data))


                    return OK;
        return ERROR;


    }
    return OK;

} // PostOrderTraverse



int main()   //������
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //�������
}//main