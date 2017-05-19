
void showMenu()
{
	//菜单选择界面;
}
#define INPUT 1
#define CHANGE 2
#define DEL 3
#define FIND 4
#define SELECT 5
#define DEAD 6
#define ALL 7
#define  MENUITEM(x,f) case x:f(); break;
int listenMenu()
{
	int op;
	scanf("%d",op);
	switch(op)
	{
		MENUITEM (INPUT,input_book)
		MENUITEM (CHANGE ,change_book)
		MENUITEM (DEL ,del_book)
		MENUITEM (FIND,find_book)
		MENUITEM (SELECT,select_book)
		MENUITEM (DEAD,deadline_book)
		MENUITEM (ALL,all_book)
		case 0:return 1;break;
		default:printerrorMenu();
	}
	showMenu();
	return 0;
}
