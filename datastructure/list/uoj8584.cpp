#include <malloc.h>
#include<cstdio>
#include <cstdlib>
#define OK 1
#define ERROR 0

//TODO: return is 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int ElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)
#define MOD(x) ((x+MAXQSIZE)%MAXQSIZE)
struct Queue
{
    ElemType *base; // 初始化的动态分配存储空间
    int front; // 头指针,若队列不空,指向队列头元素
    int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置

    Queue()
    {
        base=(ElemType *) malloc(sizeof(ElemType)*MAXQSIZE);
        front=rear=0;
    }

    Status DestroyQueue()
    {
        return OK;
    }

    Status ClearQueue()
    {
        return OK;
    }

    int QueueEmpty()
    {
        if(front ==rear)
            return 1;
        return 0;
    }

    int GetLength()
    {
        return MOD(rear-front);
    }


    ElemType  GetHead()
    {   if(front ==rear)return ERROR;
        ElemType e=base[front];
         return e;
        return OK;
    }


    Status EnQueue(ElemType e)
    {
        if(MOD(rear +1) == front) return ERROR;

        base[rear]=e;

        rear =MOD(rear +1);
        return OK;

    }

    ElemType DeQueue()
    {
        if(front ==rear)return ERROR;
        ElemType e=base[front];
        front=MOD(front +1);
        return e;
    }


    Status QueueTraverse()
    {
// 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
        int i;
        i=front;
        if(GetLength()==0)printf("The Queue is Empty!");  //请填空
        else
        {
            printf("The Queue is: ");
            while(i!=rear)     //请填空
            {
                printf("%d ",base[i]);   //请填空
                i = MOD(i+1);   //请填空
            }
        }
        printf("\n");
        return OK;
    }

};



int main()
{
    int a;
    Queue Q;
    ElemType x, e;
    if(&Q)    // 判断顺序表是否创建成功，请填空
    {
        printf("A Queue Has Created.\n");
    }

    while(1)
    {
        printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            scanf("%d", &x);
            if(!Q.EnQueue(x)) printf("Enter Error!\n"); // 判断入队是否合法，请填空
            else printf("The Element %d is Successfully Entered!\n", x);
            break;
        case 2:
            if((e=Q.DeQueue())==0) printf("Delete Error!\n"); // 判断出队是否合法，请填空
            else printf("The Element %d is Successfully Deleted!\n", e);
            break;
        case 3:
            if((e=Q.GetHead())==0)printf("Get Head Error!\n"); // 判断Get Head是否合法，请填空
            else printf("The Head of the Queue is %d!\n", e);
            break;
        case 4:
            printf("The Length of the Queue is %d!\n",Q.GetLength());  //请填空
            break;
        case 5:
            Q.QueueTraverse(); //请填空
            break;
        case 0:
            return 1;
        }
    }
}
