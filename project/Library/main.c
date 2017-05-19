#include <stdio.h>
#include <stdlib.h>
#include <meun.h>

void showLogin()
{
	//TODO: 登录界面
}
void printerror()
{
	//todo：密码登录错误信息；
}
char id[20],pass[20];
void input()
{
     //输入账号密码；

}
struct {
	char id[20];
	char pass[20];
}userinfo;


typedef struct  {
    int length;
} Qlist ;
Qlist passdata;

int match()
{	for(int i=0;i<passdata.length;i++){
    	if(strcmp(passdata[i].id,id)){
    		if(strcmp(passdata[i].pass,pass)){
    			return 1;
    		}else{

                return 0;
    		}
    	}
   }

   return 0;
}


int tryLogin()
{
	input();
	if(match()) return 1;
	else{
		printerror();
		showLogin();
		return 0;
	}

}

struct
{
	int  book_num[20];
	char book_name[20];
	char book_writer[20];
	char book_pub[20];
	char book_type[20];
	int book_deadlinetime;

} book ;
Linklist Library;
void input_book()
{
	book B;
	printbook();
     scanf("%d%s%s%s",&B.book_num,
     	B.book_name,B.book_writer,B.book_pub);
    insertlist(B);
}
#define NUM 1
#define NAME 2
#define WRITER 3
#define PUB 4
book change_B;
void change_book()
{
	book B;
	printbook_name();
	scanf("%s",B.book_name);
	printf("提示修改地方",);
	char op;
	scanf("%c",op);

	change_B=Library.find(B.book_name);
	switch(op)
	{
		MENUITEM(NUM,book_num)
		MENUITEM(NAME,book_name)
		MENUITEM(WRITER,book_writer)
		MENUITEM(PUB,book_pub)
		case 0:return 1;break;
		default:printerrorchange_book();
	}


}
void book_num()
{
      printf("//\n");
      scanf("%d",&change_B.book_num);

}
void del_book()
{
	book B;
	printbook_name();
	scanf("%s",B.book_name);
	change_B=Library.del(B.book_name);

}
void find_book()
{
	book B;
	printbook_name();
	scanf("%s",B.book_name);
	change_B=Library.find(B.book_name);
	printbook();
}
void select_book()
{
	char type[20];
	printbook_type();
	scanf("%s",type);

	//遍历链表
	if(strcmp(type,change_B.book_type) )
	printfbook();

}
void deadline_book()
{
	int time;
    printbook_time();
    scanf("%d",&time);

	//遍历链表
	if(time-change_B.book_time < 604800)
	printfbook();
}
void all_book()
{
	//遍历链表
	printbook();
}
void Init()
{
    FILE *fp_user,*fp_book;
    userinfo user;
    fp_user=fopen("user.txt","r+");

    while(fscanf(fp_user,"%s%s",user.id,user.pass)>0)
   		 passdata.insert(user);

   	book B;
    fp_book=fopen("book.txt","rw+");
    while(fscanf(fp_book,"%d%s%s%s%s%d",&B.book_num,
    	B.book_name,B.book_writer,B.book_pub,B.book_type,&B.book_deadlinetime)>0)
    	Library.insert(B);
   fclose(fp_book);
   fclose(fp_user);

}
void savefile()
{

    freopen("book.txt","w",stdout);
	//遍历链表
    printbook();
}

int main(){

	Init();

	showLogin();

	while(!tryLogin());

	showMenu();
	while(!listenMenu());
	savefile();

	return 0;
}
