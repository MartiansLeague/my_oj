#include<malloc.h>
#include<stdio.h>
#include <cctype>
#include <stack>

#include <iostream>
#define Status int
#define OK 1
#define ERROR 0
#define Dif -1


using namespace std;


#define ADD ('+')
#define SUB ('-')
#define MUL ('*')
#define DIV ('/')
#define RR  (')')
#define LR  ('(')
#define EQ  ('=')


#define LF  '>'
#define RF  '<'
#define EF  '='

int run(int a,char  op, int  b )

{
    switch(op)
    {
    case MUL:
        return a*b;
    case DIV:
        return b/a;
    case SUB:
        return b-a;
    case ADD:
        return a+b;

    }


}


Status PrecedeStack(char optr, char c)
{
    switch(optr)
    {
    case ADD:
    case SUB:
        switch(c)
        {
        case ADD:
        case SUB:
        case RR:
        case EQ:
            return LF;
        case LR:
        case MUL:
        case DIV:
            return RF;

        }

    case MUL:
    case DIV:
        switch(c)
        {
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case EQ:
        case RR:
            return LF;
        case LR:
            return RF;

        }
    case LR:
        switch(c)
        {
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case LR:
            return RF;
        case RR:
            return EF;
        case EQ:
            return ERROR;
        }
    case RR:
        switch(c)
        {
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case RR:
        case EQ:
            return LF;
        case LR:
            return ERROR;
        }
    case EQ:
        switch(c)
        {
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case LR:
        case RR:
            return RF;
        case EQ:
            return ERROR;
        }


    }
    return ERROR;

}
#define D(CH) (CH-'0')

int aln()
{
    stack<int> nums;
    stack<char> ops;
    ops.push(EQ);

    char ch;

    int num;
    ch=getchar();
    while(ch!='=' || ops.top()!=EQ)
    {

        if(ch>='0' && ch <='9')
        {
            num=D(ch);
            while(isdigit((ch=getchar())))
            {
                num*=10;
                num+=D(ch);
            }
            nums.push(num);
        }

        switch(PrecedeStack(ops.top(),ch))
        {
        case RF:
            ops.push(ch);
            ch=getchar();
            break;
        case LF:
            char op;
            int a,b;

            op=ops.top(); ops.pop();
            a=nums.top();nums.pop();
            b=nums.top();nums.pop();
            int res;
            res= run(a,op,b);
            nums.push(res);
            break;
        case EF:
            ops.pop();
            ch=getchar();
            break;
        case ERROR:
            return -1;
        }

    }

    return nums.top();

}


int main()
{

    cout<<aln();



    return 0;
}
