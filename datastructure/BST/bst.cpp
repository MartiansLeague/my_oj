/*
 用函数实现如下二叉排序树算法： （
 1）	插入新结点 （
 2）	前序、中序、后序遍历二叉树 （
 3） 中序遍历的非递归算法 （
 4）	层次遍历二叉树 （
 5）	在二叉树中查找给定关键字(函数返回值为成功1,失败0)


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

*/


#include <cstdio>
#include <malloc.h>
#include <iostream>

#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int  Status;
typedef int  ElemType;


using namespace std;


//core
struct BSTree
{
    ElemType data;
    struct BSTree *lchild,*rchild;//左右孩子指针

    BSTree()
    {
        rchild=lchild=nullptr;
    }
    void PrintElement()
    {
        cout<<data<<" ";
    }
    Status PreOrderTraverse()
    {
        PrintElement();
        lchild!=nullptr && lchild->PreOrderTraverse();
        rchild!=nullptr && rchild->PreOrderTraverse();
        return OK;
    }
    Status Leave()
    {
        if(lchild == nullptr  && rchild ==nullptr)
            return true;
        return false;
    }
    Status Search(ElemType t,BSTree * &p )
    {   p=this;
        if(data==t) {  return true;}
        if(t<data &&  lchild !=nullptr) return lchild->Search(t,p);
        if(t>data &&  rchild !=nullptr) return rchild->Search(t,p);
        return false;
    }
    Status Insert(ElemType k){
        BSTree *p;
        if(!Search(k,p)){
            BSTree * s=(BSTree *) malloc(sizeof (BSTree));
            s->data=k; s->lchild=s->rchild=nullptr;

            if(k<p->data) p->lchild=s;
            else p->rchild=s;
            return true;
        }
        return false;

    }
    Status InOrderTraverse(){

        lchild!=nullptr && lchild->PreOrderTraverse();
        PrintElement();
        rchild!=nullptr && rchild->PreOrderTraverse();
        return OK;
    }
    Status PostOrderTraverse( ){

        lchild!=nullptr && lchild->PreOrderTraverse();
        rchild!=nullptr && rchild->PreOrderTraverse();
        PrintElement();
        return OK;
    }
};

class BST{

private:
    BSTree T;
    int count=0;
public:
    void insert(ElemType k){
        if(!count){
            T.data=k;
        }else{
            T.Insert(k);
        }
        count++;
    }

    void PreOrder(){
        T.PreOrderTraverse();
        cout<<endl;
    }
    void PostOrder(){
        T.PostOrderTraverse();
        cout<<endl;
    }
    void InOrder(){
        T.InOrderTraverse();
        cout<<endl;
    }
};


int main()   //主函数
{
    BST T;

    int n;
    cin>>n;
    int t;
    while(n--){
        cin>>t;
        if(t==18){
            1+1;
        }
        T.insert(t);
        T.PreOrder();
        T.InOrder();
        T.PostOrder();
    }


}//main
