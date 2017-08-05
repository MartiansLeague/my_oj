#include "goods.h"

int main(){

	Store * S;
	S=InitStore();

	AddGoods(*S,1,"1111",2);
	AddGoods(*S,2,"2111",3);
	AddGoods(*S,3,"2111",3);
	AddGoods(*S,4,"2111",3);
	AddGoods(*S,5,"2111",3);
	AddGoods(*S,6,"2111",3);
	ShowAllGoods();

	printf("\n");

	ChangeGoodsName(*S,1,"5555");
	if(ChangeGoodsName(*S,5555,"5555")){
		printf("can't find goods by id:%d",5555);
	};

	ChangeGoodsCount(*S,2,555);

	ShowAllGoods();


	return 0;
}