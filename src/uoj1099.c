/*

**************************************
1099 [填空题]链表的合并
**************************************
Description
下面程序创建两个链表，然后将第二个链表合并到第一个链表未尾，但合并部分的代码未完成，请你完成这部分代码。
**************************************
Sample Input

2			（the 1st linked list, 2 students）

1			（code of no.1 studentof the 1st linked list）

98			（score of no.1 student of the 1st linked list）

7			（code of no.2 student of the 1st linked list）

99			（score of no.2 student of the 1st linked list）

1			（the 2nd linked list, 1 student）

5			（code of no.1 student of the 2nd linked list）

87			（score of no.1 student of the 2nd linked list）


**************************************
Sample Output

       1      98

       7      99

       5      87

       1      98

       7      99

       5      87


**************************************
Author0*/
#include "stdio.h" 
#include "malloc.h" 
#define LEN sizeof(struct student) 

struct student 
{ 
     long num; 
     int score; 
     struct student *next; 
}; 

struct student *create(int n) 
{  
     struct student *head=NULL,*p1=NULL,*p2=NULL; 
     int i; 
     for(i=1;i<=n;i++) 
     {  p1=(struct student *)malloc(LEN); 
        scanf("%ld",&p1->num);     
        scanf("%d",&p1->score);     
        p1->next=NULL; 
        if(i==1) head=p1; 
        else p2->next=p1; 
        p2=p1; 
      } 
      return(head); 
} 

struct student *merge(struct student *head, struct student *head2) 
{  
    struct student *p; 
    p=head; 
    while(p!=NULL) 
    { 
        if(p->next==NULL) {
            p->next =head2;
            return head;
        }
        p=p->next; 
    } 

} 


void print(struct student *head) 
{ 
    struct student *p; 
    p=head; 
    while(p!=NULL) 
    { 
        printf("%8ld%8d",p->num,p->score); 
        p=p->next; 
        printf("\n"); 
    } 
} 

main() 
{ 
    struct student *head, *head2; 
    int n; 
    long del_num; 
    scanf("%d",&n);  
    head=create(n); 
    print(head); 
    scanf("%d",&n);  
    head2=create(n); 
    print(head2); 
    head = merge(head, head2);     
    print(head); 
} 
