#ifndef List_H
#define List_H 1

#include <cstdarg> 
#include <iostream>
namespace {
#define Show(i) if(this->visual==i) toxpmstr();
	template <class T>  using ptr = T*;
}

template <class T>
class List {
private:
	ptr<T> elem=nullptr;
	int size=0;
	int len=0;
	int visual = 0;//输出可视级别，0为静默
	
	mutable int fillpos=0;//填充位置
	void(*callback)(char *);//序列化回调函数

	inline void printelem(T e) const {
		cout << e << endl;
	}

	inline void resetpos() const{
		fillpos = 0;
	}
public:

	List(int s=102400) {
		elem = (T*)malloc(sizeof(T)*s);
		size = s;
		len = 0;
		fillpos = 0;
	}


	/*basic operator*/
	inline int length() const {
		return len;
	}
	inline T  front() const {
		return elem[0];
	}

	inline T* begin() const {
		return elem;
	}

	inline T* end() const {
		return elem + len;
	}

	/*data*/
	void resize(int newsize) {//TODO
		elem = (T*)realloc(elem, newsize);
		size = newsize;
	}

	void append(T e) {
		//TODO
		elem[len++] = e;
		if (len > size - 2)
			resize(size * 2);//伙伴系统
	}
	void fillrandom(int count, T min, T max,int seed=42) {
		/*42 is the answer for everything ：）*/
		/*TODO： type 假设T为数字类型，其他类型不能用*/
		if (size <= count) 
			resize(count * 2);//todo

		srand(seed);
		for (int i = 0; i < count; i++) {
			T num = (T)((((double)rand() / RAND_MAX)*(max - min + 1)) + min);
			elem[i] = num;
		}
		len = count;
	}

	/*多参数*/
	template<typename... Args>
	void fill(T a,Args... b ) {
		if (fillpos == 0) len = sizeof...(b)+1;
		elem[fillpos++] = a;
		fill(b...);
	}
	void fill(T a) {
		if (fillpos == 0) len =1;//主动调用
		elem[fillpos] = a;
		fillpos = 0;//终点
	}
	void fill() {
		/*置零*/
		len = 0;
	}
	/*visualable*/
	void print() { /*inline display*/
		for (int i = 0; i < len; i++) 
			/*Don't use the `using namespace std;` in head file QAQ*/
			std::cout << elem[i] << " ";
		std::cout << std::endl;
	}
	/*output to xpm image */
	void setvisual(int lv) {
		visual = lv;
	}
	void setcallback(void(*f)(char *)) {
		callback = f;
	}
	void toxpmstr() {
		char * out;
		int i;
		out = (char *)malloc(len + 2);
		for (i = 0; i < len; i++) {
			out[i] =elem[i]+'#';
		}
		out[i] = 0;
		callback(out);
	}
	/**************SORT********************/
private:
	/*common*/
	static inline void swap(T&a, T &b) {
		T temp; temp = a; a = b; b = temp;
	}
	 int minpos(int  s, int e)const {
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
	 void _heapfit(int s, int end);
	 int patch(int start, int end);
	 int patch(T *nums, int end);
	 void ShellInsert(int dk);
public:
	void SelectSort();
	void HeapSort();
	void qsort(int s, int e);
	void Popsort();
	void ShellSort(int delta[], int t);
};

template <class T>
void List<T>::ShellInsert(int dk) {
	T temp;
	for (int i = dk; i < len; ++i) {
		if (elem[i]<elem[i - dk]) {
			temp = elem[i];
			int j;
			for (j = i - dk; j >= 0 && temp<elem[j]; j -= dk)
				elem[j + dk] = elem[j];
			elem[j + dk] = temp;
			Show(3);
		}
		Show(2);
	}
	Show(1);
}

template <class T>
int List<T>::patch(T *nums, int end) {
	int flag = 0;
	for (int i = 0; i < end; ++i) {
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

template <class T>
int List<T>::patch(int start, int end) {
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

template <class T>
void List<T>::_heapfit(int s, int end) {
	int t = elem[s];
	for (int j = 2 * s; j <= end; j *= 2) {
		if (j<end && elem[j]<elem[j + 1])
			j++;
		if (t >= elem[j])
			break;
		elem[s] = elem[j];
		s = j;
		Show(2);
	}
	elem[s] = t;
	Show(1);
}


template <class T>
void List<T>::SelectSort() {
	for (int i = 0; i<len - 1; ++i) {
		int pos = minpos(i, len);
		swap(elem[i], elem[pos]);
		Show(1);
	}
}

template <class T>
void List<T>::HeapSort() {
	for (int i = len / 2; i >= 0; i--)
		_heapfit(i, len - 1);
	for (int i = len - 1; i >= 1; --i) {
		swap(elem[1], elem[i]);
		_heapfit(1, i - 1);
	}
}

template <class T>
void List<T>::qsort(int s, int e) {
	if (s<e) {
		int p = patch(s, e);
		qsort(s, p - 1);
		qsort(p + 1, e);
		Show(1);
	}
}

template <class T>
void List<T>::ShellSort(int delta[], int t) {
	for (int k = 0; k<t; k++) {
		ShellInsert(delta[k]);
	}
}

template <class T>
void List<T>::Popsort() {
	for (int i = len - 1; i >= 1; --i)
		if (!patch(elem, i)) return;
}

#undef Show
#endif // !List_H
