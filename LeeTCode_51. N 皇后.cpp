#include<iostream>
#include<malloc.h>
using namespace std;
#define FX(i) (n - i + j-1)
#define ZX(i) (i+j)
#define fuzhi(x) \
b[0][j] = x; \
b[1][FX(i)] = x; \
b[2][ZX(i)] = x;

#define shuchu() \
for(int t=0;t<n;t++)\
for(int y=0;y<n;y++)\
{if(idex[t]==y) qqq[num][t][y] = 'Q';\
else qqq[num][t][y] = '.';\
qqq[num][t][n]='\0';\
}

char*** solveNQueens(int n, int* returnSize) {
	int num = 0;
	int j=0;
	int b[3][17] = { 0 };
	char*** qqq=(char ***)malloc(sizeof(char **)*501);
	for (int i = 0; i < 501; ++i) {
		qqq[i] = (char**)malloc(sizeof(char*) * n);
		for (int y = 0; y < n; ++y)
			qqq[i][y] = (char*)malloc(sizeof(char) * (n));
	}
	int idex[9];
	for (int i = 0; i < n; ) {
		for (; j < n; ++j) {
			if (!(b[0][j] | b[1][FX(i)] | b[2][ZX(i)])) {
				idex[i] = j; 
				if (i == n - 1) {
					shuchu();
					++num;
					if (!i) {
						j = n;
						break;
					}
					--i;
					j = idex[i];
					fuzhi(0);
					continue;
				}
				fuzhi(1);
				++i;
				j = 0;
				break;
			}
		}
		if (j == n) {
			if (!i) {
				for (int e = 0; e < num; ++e) {
					for (int y = 0; y < n; ++y) {
						for (int pp = 0; pp < n; ++pp)
							cout << qqq[e][y][pp] << " ";
						cout << " ";
					}
					cout << endl;
				}
				cout << num;
				return qqq;
			}
			--i;
			j = idex[i] ;
			fuzhi(0);
			++j;
		}
	}
	return qqq;
}
int main() {
	int* a = (int*)malloc(sizeof(int));
	int** b = (int**)malloc(sizeof(int));
	solveNQueens(9, a);
}
