#ifndef List_H
#define List_H 1

#include <cstdarg> 
#include <iostream>
#define Show(i) if(visual==i) xpmbody();

template <class T>
class List {
private:
	T *elem;
	int size;
	int len;
	int visual = 0;
	void printelem(T e) {
		cout << e << endl;
	}
	void (*fn)(char *);
public:

	void setfn(void (*f)(char *)) {
		fn = f;
	}
	List(int s=1000000) {
		elem = (T*)malloc(sizeof(T)*s);
		size = s;
		len = 0;
		setpos = 0;
	}


	void swap(T&a, T &b) {
		T temp;

		temp = a;
		a = b;
		b = temp;
	}
	int length() {
		return len;
	}
	T front() {
		return elem[0];
	}
	T * begin() {
		return elem;

	}
	T* end() {
		return elem + len;
	}
	void append(T e) {
		//TODO
		elem[len++] = e;
		if (len > size - 2) {
			resize(size * 2);
		}
	}
	
	/********Ï£¶ûÅÅÐò***************/
	void ShellInsert(int dk) {
		T temp;
		for (int i = dk ; i < len; ++i) {
			if (elem[i]<elem[i - dk]) {
				temp = elem[i];
				int j;
				for (j = i - dk; j>=0 && temp<elem[j]; j -= dk)
					elem[j + dk] = elem[j];
				elem[j + dk] = temp;
				if(visual==3)xpmbody();
			}
			if (visual == 2)xpmbody();
		}
		if (visual == 1)xpmbody();

	}

	void ShellSort(int delta[], int t) {
		for (int k = 0; k<t; k++) {
			ShellInsert(delta[k]);
		}
	}
	

	int setpos;
	/*¶à²ÎÊý*/
	template<typename... Args>
	void set(T a,Args... b ) {
		if (setpos == 0) len = sizeof...(b)+1;
		elem[setpos++] = a;
		set(b...);
	}
	void set(T a) {
		if (setpos == 0) len =1;
		elem[setpos] = a;
		setpos = 0;
	}
	void set() {
		len = 0;
	}

	void resize(int newsize) {
		elem=(T*)realloc(elem, newsize);
	}

	void print() {
		for (int i = 0; i < len; i++) {
			std::cout << elem[i]<<" ";
		}
		std::cout << std::endl;	
	}
	void xpmbody() {
		char * out;
		int i;
		out = (char * )malloc(len + 2);
			for (i= 0; i < len; i++) {
				out[i] = '#'+64- elem[i];
			}
		out[i] = 0;
		fn(out);
	}


	int patch(T *nums, int end) {
		int flag = 0;
		for (int i = 0; i<end; ++i) {

			if (nums[i] > nums[i + 1]) {
				swap(nums[i], nums[i + 1]);
				flag = 1;
				Show(3);
			}
			Show(2);
			
		}
		Show(1);
		return flag;

	}
	void popsort() {
		for (int i = len-1; i >=1; --i) 
			if (!patch(elem, i)) return;
	}


	int patch( int start, int end) {

		T temp = elem[start];
		while (start<end) {
			while (start<end && elem[end] >= temp) end--;
			elem[start] = elem[end];

			while (start<end && elem[start] <= temp) start++;
			elem[end] = elem[start];
			Show(3);
		}

		elem[start] = temp;
		Show(2);
		return start;

	}
	void qsort(int s, int e) {
		
		if (s<e) {
			int p = patch( s, e);
			qsort( s, p - 1);
			qsort(p + 1, e);
			Show(1);
		}

	}

	int minpos(int  s, int e) {
		int p = s;
		int mi = elem[s];
		for (int i = s; i < e; i++) {

			if (elem[i]<mi) {
				p = i;
				mi = elem[i];
			}
		}
		return p;

	}
	void SelectSort() {

		for (int i = 0; i<len-1; ++i) {
			int pos = minpos(i, len);
			swap(elem[i], elem[pos]);
			Show(1);
		}

	}


	void fit( int s, int end) {
		int t = elem[s];
		for (int j = 2 * s; j <= end; j *= 2) {

			if (j<end && elem[j]<elem[j + 1]) {
				j++;
			}

			if (t >= elem[j]) {
				break;
			}

			elem[s] = elem[j];
			s = j;
			Show(2);
		}
		elem[s] = t;
		Show(1);
	}
	void HeapSort() {
		for (int i = len / 2; i>=0; i--) 
			fit( i, len-1);
		for (int i = len-1; i>=1; --i) {
			swap(elem[1], elem[i]);
			fit( 1, i - 1);
		}

	}
	void setvisual(int lv) {
		visual = lv;
	}

	void outputxpm() {
		x.build();
	}

	void fillrandom(int count, T min, T max) {
		if (size <= count) {
			resize(count * 2);//todo
		}
		srand(123455);
		for (int i = 0; i < count; i++) {
			T num = (T)((((double)rand() / RAND_MAX)*(max - min+1) )+ min);
			elem[i] = num;
		}
		len = count;
		
	}
};

#endif // !List_H
