#include<iostream>
#include<malloc.h>
using namespace std;
#define push(x) stack[++top]=i
#define pop() --top

int largestRectangleArea(int* heights, int heightsSize) {
	int* stack = (int*)malloc(sizeof(int) * (heightsSize+1));
	int top = 0,max=0,x;
	stack[0] = -1;
	for (int i = 0; i < heightsSize; ++i) {
		while(top>0&&heights[stack[top]]> heights[i]) {
			x =heights[ stack[top]] * (i - stack[top-1]-1);
			max = (max > x) ? max : x;
			pop();
		}
		push(heights[i]);
	}
	--heightsSize;
	while (top > 0) {
		x = heights[stack[top]] * (heightsSize - stack[top - 1]);
		max = (max > x) ? max : x;
		pop();
	}
	return max;
}

int main() {
	int s[6] = { 2,4};
	cout<< largestRectangleArea(s, 2);
}
