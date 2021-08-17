#include<iostream>
#include<malloc.h>
using namespace std;

int maximalRectangle(char matrix[][6], int matrixSize, int* matrixColSize) {
	int max = 0, top = 0;
	if (matrixSize == 0 || matrixColSize == NULL)
		return max;
	++* matrixColSize;
	short* stack = (short*)malloc(sizeof(short) * *matrixColSize);
	stack[0] = 0;
	short* sz = (short*)malloc(sizeof(short) * *matrixColSize);
	sz[0] = -1;
	for (int i = 0; i < *matrixColSize; ++i)
		sz[i] = 0;
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 1; j < *matrixColSize; ++j)
			sz[j] = (sz[j] + 1) * (matrix[i][j - 1] == '1');
		int k = 1;
		while (k < *matrixColSize) {
			while (sz[stack[top]] > sz[k]) {
				int m = sz[stack[top]] * (k - stack[top - 1] - 1);
				max = (max > m) ? max : m;
				--top;
			}
			stack[++top] = k++;
		}
		while (stack[top] > 0) {
			int m = sz[stack[top]] * (k - stack[top - 1] - 1);
			max = (max > m) ? max : m;
			--top;
		}
	}
	return max;
}

int main() {
	char s[ ][6] = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	int i = 6;
	cout<< maximalRectangle(s, 4,&i);
}
