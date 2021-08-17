#include<iostream>
#include<malloc.h>
using namespace std;

int firstMissingPositive(int* height, int heightSize) {
	int* a, * b;
	a = (int*)malloc(sizeof(int) * heightSize);
	b = (int*)malloc(sizeof(int) * heightSize);
	int   min;
	a[0] = -1; b[0] = 0;
	int num = 0;
	for (int i = 1; i < heightSize; ++i) {
		if (height[i] >= height[i - 1]) {
			a[i] = a[i - 1];
			b[i] = b[i - 1] + height[i - 1]; cout << b[i] << " ";
			if (a[i] == -1 || (height[i] == height[i - 1]))continue;
			do {
				min = ((height[i] < height[a[i]]) ? height[i] : height[a[i]]) * (i - a[i] - 1);
				num += min - b[i];
				if (height[i] < height[a[i]]) {
					b[i] = min;
					break;
				}
				else b[i] = min + b[a[i]] + height[a[i]];
				a[i] = a[a[i]];
			} while (a[i] != -1);
		}
		else {
			a[i] = i - 1;
			b[i] = 0;
		}
	}
	return num;
}
int main() {
	int s[] = { 5,5,1,7,1,1,5,2,7,6 };
	cout << firstMissingPositive(s, sizeof(s) / sizeof(s[0]));
}
