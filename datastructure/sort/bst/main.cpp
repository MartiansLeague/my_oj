#include <malloc.h>
#include <iostream>
#include <stack>
#include <queue>
#define OK  1
#define ERROR  0

/*渣渣oj，毁我青春*/
#define nullptr (0)

typedef int  Status;
typedef int  ElemType;

using namespace std;
struct BSTree
{
    ElemType data;
    struct BSTree *lchild,*rchild;
    BSTree();
    void PrintElement();
    Status Leave();
    Status Search(ElemType t,BSTree * &p );
    Status Insert(ElemType k);
    Status InOrderTraverse();
    Status InOrderStack();
    Status PreOrderTraverse();
    Status PostOrderTraverse( );
    Status LevelOrderTraverse();
};

//core

BSTree::BSTree()
{
    rchild=lchild=nullptr;
}
void BSTree::PrintElement()
{
    cout<<data<<" ";
}
Status BSTree::Leave()
{
    if(lchild == nullptr  && rchild ==nullptr)
        return true;
    return false;
}
Status BSTree::Search(ElemType t,BSTree * &p )
{
    p=this;
    if(data==t)
    {
        return true;
    }
    if(t<data &&  lchild !=nullptr) return lchild->Search(t,p);
    if(t>data &&  rchild !=nullptr) return rchild->Search(t,p);
    return false;
}
Status BSTree::Insert(ElemType k)
{
    BSTree *p;
    if(!Search(k,p))
    {
        BSTree * s=(BSTree *) malloc(sizeof (BSTree));
        s->data=k;
        s->lchild=s->rchild=nullptr;

        if(k<p->data) p->lchild=s;
        else p->rchild=s;
        return true;
    }
    return false;

}
Status BSTree::InOrderTraverse()
{

    lchild!=nullptr && lchild->InOrderTraverse();
    PrintElement();
    rchild!=nullptr && rchild->InOrderTraverse();
    return OK;
}

Status BSTree::InOrderStack()
{
    BSTree * p=this;
    stack<BSTree *> s;
    while(p|| !s.empty())
    {
        if(p!=nullptr)
        {
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            s.pop();
            p->PrintElement();
            p=p->rchild;
        }
    }
    return OK;
}
Status BSTree::PreOrderTraverse()
{
    PrintElement();
    lchild!=nullptr && lchild->PreOrderTraverse();
    rchild!=nullptr && rchild->PreOrderTraverse();
    return OK;
}

Status BSTree::PostOrderTraverse( )
{
    lchild!=nullptr && lchild->PostOrderTraverse( );
    rchild!=nullptr && rchild->PostOrderTraverse( );
    PrintElement();
    return OK;
}

Status BSTree::LevelOrderTraverse()
{
    queue <BSTree*> q;
    BSTree * p;
    q.push(this);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        p->PrintElement();
        if(p->lchild!=nullptr ) q.push(p->lchild);
        if(p->rchild!=nullptr ) q.push(p->rchild);
    }
}



class BST
{

private:
    BSTree T;
    int count;
public:

    BST()
    {
        /*渣渣oj，毁我青春*/
        count=0;
    }
    void insert(ElemType k)
    {
        if(!count)
            T.data=k;
        else
            T.Insert(k);
        count++;
    }

    void PreOrder()
    {
        T.PreOrderTraverse();
        cout<<endl;
    }
    void PostOrder()
    {
        T.PostOrderTraverse();
        cout<<endl;
    }
    void InOrder()
    {
        T.InOrderTraverse();
        cout<<endl;
    }
    bool find(ElemType k)
    {
        BSTree *p;
        return T.Search(k,p);
    }
    void  InOrderStack()
    {
        T.InOrderStack();
        cout<<endl;
    }

    void LevelOrder()
    {
        T.LevelOrderTraverse();
        cout<<endl;
    }
};


int main()   //主函数
{
    BST T;

    int n;
    cin>>n;
    int t;
    while(n--)
    {
        cin>>t;
        T.insert(t);

    }
    T.PreOrder();
    T.InOrder();
    T.PostOrder();
    int tof;
    cin>>tof;
    cout<< (T.find(tof)?1:0)<<endl;
    cin>>tof;
    cout<< (T.find(tof)?1:0)<<endl;

    cin>>t;
    T.insert(t);
    T.PreOrder();
    T.InOrder();
    T.PostOrder();
    T.InOrderStack();
    T.LevelOrder();
}//main
