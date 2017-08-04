#include "List.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "xpm.cc"
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

Xpm * x;
void fn(char * n) {
	x->row(n);
	//printf("%s\n", n);
}
int main() {
	//freopen("test.xpm", "w",stdout );
	x=&Xpm("Show.xpm");
	List<int> L;
	L.print();
	L.fillrandom(500, 0, 35);
	int dk[] = { 33,17,9,5,3,2,1 };
	//L.set(15, 4, 26, 6, 5, 2, 16, 8, 7, 4, 18, 9, 3, 10, 1, 12, 19, 21, 24, 3, 24, 31, 17, 14, 2, 5, 2, 16, 1, 24, 2, 12, 4, 2, 12, 5, 4, 19, 1);

	L.setcallback(fn);
	L.setvisual(3);
	cout << "ShellSort" << endl;

	L.ShellSort(dk, 6);
	//L.set(5, 2, 4, 8, 1);
	//L.qsort(0, 1999);
	//L.HeapSort();
	
	x->build();
	/*
	x = &Xpm("POP.xpm");
	//L.fill(32,45,32,54,8,4,7,45,48,42,41,38,3,54,54,12,5,21,54,12,5,41,54,63,61,62,2,3,1,2,1,5,54,58,54,56,61,2,1,5,4,6,5,2,15,1,5,62,61,63);
	L.setvisual(1);
	L.popsort();
	x->build();
	*/
	/*
	for (int i = 1; i < 359; i++) {
		x->HSB_2_RGB(i, 0.5, 0.99);
	}*/
	/*
	cout << "ShellSort" << endl;
	L.SelectSort();
	L.set(5, 2, 4, 8, 1);
	
	cout << "ShellSort" << endl;
	L.set(5, 2, 4, 8, 1);
	L.qsort(0, 4);
	cout << "ShellSort" << endl;

	L.set(5, 2, 4, 8, 1);
	L.popsort();
	cout << "ShellSort" << endl;

	L.ShellSort(dk, 5);
	L.set(5, 2, 4, 8, 1);
	L.HeapSort();
	//L.xpmend();
	
	*/
	//Xpm x("test1.xpm");
	//x.test();

	system("pause");
	return 0;
}