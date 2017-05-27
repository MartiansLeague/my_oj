#include "serialize.h"

int print( LinkList L,ptr elem){
	printf("goods:%d\n",((goods *)elem)->id);
	return 0;
}

int writer(FILE * fp,goods *g){
	fwrite(g,sizeof (goods) ,1,fp);
	return 0;
}

LinkList L;

goods * reader(FILE *fp){
	goods* g;
	g=MAKE(goods);

	if(fread(g,sizeof(goods),1,fp))
	{
		return g;
	}
	
	return 0;
}
int main(){
	Store *s;
	s=InitStore();

	
	L=s->L;

	goods a,b,c;
	a.id=1;
	b.id=2;
	c.id=3;

	strcpy(a.name,"test");
	strcpy(b.name,"test");
	strcpy(c.name,"test");

	pushback(L,&a);
	pushback(L,&b);
	pushfront(L,&c);

	foreach(L,print);
	FILE * fp;
	fp=fopen("testsave.dat","wb");

	serialize(*s,fp,writer);
	fclose(fp);


	fp=fopen("testsave.dat","rb");

	unserialize(*s,fp,reader);

	/*
	goods* la,*lb,*lc;
	la=MAKE(goods);
	lb=MAKE(goods);
	lc=MAKE(goods);
	fread(la,sizeof(goods),1,fp);
	fread(lb,sizeof(goods),1,fp);
	fread(lc,sizeof(goods),1,fp);
	printf("%d %d %d\n",la->id,lb->id,lc->id);*/
	foreach(L,print);
	return 0;
}