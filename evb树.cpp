#include<iostream>
#include<sys/timeb.h>
#include<stdlib.h>
using namespace std;
#define NIL -1
#define Min(x) (x->min)
#define Max(x) (x->max)
#define ssqrt(x,z) (x>>z->sqrt)
#define xsqrt(x,z) (1<<z->sqrt)
#define high(x,z) (x>>z->sqrt)
#define low(x,z) (x%xsqrt(x,z))
#define swap(x,y)  {\
x = x + y;\
y = x - y;\
x = x - y;}
#define fuzhi(z,n) {\
z->min = n;\
z->max = n; }

typedef struct _veb {
	int v, min, max, sqrt;
	struct _veb* sum;
	struct _veb** str;
}Veb;

int index(int h, int l, Veb* z) {
	return (h << z->sqrt) + l;
}
int wei(int n) {
	int k;
	asm (
		"bsr %1,%0"
		:"=r"(k)
		:"r" (n)
	);
	return k;
}
int mi(int n) {
	if (n == (n & -n))return n;
	n=1<<wei(n);
	return n << 1;
}

bool chazhao(Veb* z, int n) {
	if (n == Min(z) || n == Max(z))
		return true;
	else if (z->v == 2)
		return false;
	else return chazhao(z->str[high(n, z)], low(n, z));
}
void add(Veb* z, int n) {
	if (Min(z) == NIL) {
		fuzhi(z, n);
	}
	else {
		if (n < Min(z)) {
			swap(z->min, n);
		}
		if (z->v > 2)
			if (Min(z->str[high(n, z)]) == NIL) {
				fuzhi(z->str[high(n, z)], low(n, z));
				add(z->sum, high(n, z));
			}
			else add(z->str[high(n, z)], low(n, z));
		if (n > Max(z))
			z->max = n;
	}
}
int hou(Veb* z, int n) {
	if (z->v == 2)
		if (n == 0 && Max(z) == 1)
			return 1;
		else return NIL;
	else if (Min(z) != NIL && n < Min(z))
		return Min(z);
	else {
		int s_max = Max(z->str[high(n, z)]);
		if (s_max != NIL && low(n, z) < s_max)
			return index(high(n, z), hou(z->str[high(n, z)], low(n, z)), z);
		else {
			int u_max = hou(z->sum, high(n, z));
			if (u_max == NIL)
				return NIL;
			else return index(u_max, Min(z->str[u_max]), z);
		}
	}
}
int qian(Veb* z, int n) {
	if (z->v == 2)
		if (n == 1 && Min(z) == 0)
			return 0;
		else return NIL;
	else if (Max(z) != NIL && n > Max(z))
		return Max(z);
	else {
		int min = Min(z->str[high(n, z)]);
		if (min != NIL && low(n, z) > min)
			return index(high(n, z), qian(z->str[high(n, z)], low(n, z)), z);
		else {
			min = qian(z->sum, high(n, z));
			if (min == NIL)
				if (Min(z) != NIL && n > Min(z))
					return Min(z);
				else return NIL;
			else return index(min, Max(z->str[min]), z);
		}
	}
}

void dele(Veb* z, int n) {
	if (Min(z) == Max(z)) {
		fuzhi(z, NIL);
	}
	else if (Max(z) == n) {
		if (z->v == 2)
			z->max = 0;
		else {
			dele(z->str[high(n, z)], low(n, z));
			int max = Max(z->str[high(n, z)]);
			if (max == NIL) {
				dele(z->sum, high(n, z));
				max = Max(z->sum);
				if (max == NIL)
					z->max = z->min;
				else z->max = index(max, Max(z->str[max]), z);
			}
			else z->max = index(high(n, z), max, z);
		}
	}
	else if (Min(z) == n) {
		int min = Min(z->sum);
		while (z->v != 2 && Min(z->str[min]) != Max(z->str[min])) {
			z->min = index(min, Min(z->str[min]), z);
			z = z->str[min];
			min = Min(z->sum);
		}
		if (z->v == 2)
			z->min = 1;
		else {
			z->min = index(min, Min(z->str[min]), z);
			fuzhi(z->str[min], NIL);
			dele(z->sum, min);
		}
	}
	else dele(z->str[high(n, z)], low(n, z));
}
bool delete_veb(Veb* z, int n) {
	if (chazhao(z, n)) {
		dele(z, n);
		return true;
	}
	else return false;
}
Veb* suanjian(int n) {
	Veb* z = (Veb*)malloc(sizeof(Veb));
	z->v = n;
	z->min = NIL;
	z->max = NIL;
	if (n > 2) {
		z->sqrt = wei(n) / 2;
		z->sum = suanjian(ssqrt(n, z));
		z->str = (Veb**)malloc(sizeof(Veb*) * ssqrt(n, z));
		for (int i = 0; i < ssqrt(n, z); ++i) {
			z->str[i] = suanjian(xsqrt(n, z));
		}
	}

	return z;
}
int main() {
	Veb* root = suanjian(mi(7000000));
	srand(100);
	int max=0;
	for(int i=0;i<5000000;++i){
	int k=rand();
	if(k>max) max=k;
	add(root,k);}
	cout<<Max(root)<<" "<<max<<" ";
	cout << "1、添加（个数 数据） 2、删除（数据）" << endl;
	while (1) {
		int a;
		cin >> a;
		switch (a) {
		case 1:
			int c, m;
			cin >> c;
			for (int i = 0; i < c; ++i) {
				cin >> m;
				add(root, m);
				cout << "前：" << qian(root, m) << "后：" << hou(root, m) << endl;
			}
			break;
		case 2:
			int w;
			cin >> w;
			cout << "前：" << qian(root, w) << "后：" << hou(root, w) << endl;
			delete_veb(root, w);
		}
	}
}
