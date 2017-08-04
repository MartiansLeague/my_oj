
typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位

    SqStack()
    {
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
        base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
        top=base;
        stacksize=STACK_INIT_SIZE;
    }

    Status Push(SElemType e)
    {
// 在栈S中插入元素e为新的栈顶元素
        if(top-base>=stacksize)
        {
            base=(SElemType*)realloc(base,(stacksize+STACKINCREMENT)*sizeof(SElemType));
            if(!base) return ERROR;
            top=base+stacksize;
            stacksize+=STACKINCREMENT;
        }
        *top++=e;
        return OK;
    }

    Status Pop()
    {
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
        if(top==base) return ERROR;
        --top;
        return OK;
    }

    Status GetTop(SElemType &e)
    {
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
        if(top==base) return ERROR;
        e=*(top-1);
        return OK;
    }

    int StackLength()
    {
// 返回栈S的元素个数

        return top-base;;
    }

    Status StackTraverse()
    {
// 从栈顶到栈底依次输出栈中的每个元素
        SElemType *p = (SElemType *)malloc(sizeof(SElemType));
        p = top;
        if(top==base)printf("The Stack is Empty!");
        else
        {
            printf("The Stack is: ");
            p--;
            while(p>=base)
            {
                printf("%d ", *p);
                p--;
            }
        }
        printf("\n");
        return OK;
    }


}; // 顺序栈

