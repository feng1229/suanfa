
#include<iostream>
#include<malloc.h>
using namespace std;

char* getPermutation(int n, int k) {
	int ii;
	int* a = (int*)malloc(sizeof(int) * (n + 1));
	char* wh = (char*)malloc(sizeof(char) * n);
	char* q = (char*)malloc(sizeof(char) * (n + 1));
	a[1] = 1;
	for (int i = 2; i <= n; ++i) {
		a[i] = i * a[i - 1];
		wh[i - 1] = i + '0';
	}
	wh[0] = '1';
	--k;
	for (int i = 1; i <= n; ++i) {
		ii = k % a[n - i + 1] / a[n - i];
		q[i - 1] = wh[ii];
		for (; ii < n - i; ++ii)
			wh[ii] = wh[ii + 1];
	}
	q[n] = '\0';
	return q;
}
int main() {
	 cout<<getPermutation(4, 8);
}
