/*
 用函数实现如下二叉排序树算法： （1）	插入新结点 （2）	前序、中序、后序遍历二叉树 （3） 中序遍历的非递归算法 （4）	层次遍历二叉树 （5）	在二叉树中查找给定关键字(函数返回值为成功1,失败0)


输入格式
第一行：准备建树的结点个数n
第二行：输入n个整数，用空格分隔
第三行：输入待查找的关键字
第四行：输入待查找的关键字
第五行：输入待插入的关键字


输出格式
第一行：二叉树的先序遍历序列
第二行：二叉树的中序遍历序列
第三行：二叉树的后序遍历序列
第四行：查找结果
第五行：查找结果
第六行~第八行：插入新结点后的二叉树的先、中、序遍历序列
第九行：插入新结点后的二叉树的中序遍历序列(非递归算法)
第十行：插入新结点后的二叉树的层次遍历序列


输入样例
7
40 20 60 18 50 56 90
18
35
30


输出样例
40 20 18 60 50 56 90
18 20 40 50 56 60 90
18 20 56 50 90 60 40
1
0
40 20 18 30 60 50 56 90
18 20 30 40 50 56 60 90
18 30 20 56 50 90 60 40
18 20 30 40 50 56 60 90
40 20 60 18 30 50 90 56


作者 yqm
提交
*/


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
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)    // 算法6.4
{
    // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
    // 构造二叉链表表示的二叉树T。
    char ch;
    scanf("%c",&ch);
    if (ch=='#') T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        T->data=ch; // 生成根结点
        CreateBiTree(T->lchild)  ;  // 构造左子树
        CreateBiTree(T->rchild)  ;   // 构造右子树
    }
    return OK;
} // CreateBiTree


Status PrintElement( ElemType e )    // 输出元素e的值
{
    printf("%c", e );
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句

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
    // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句

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
    // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
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



int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //补充代码
}//main
