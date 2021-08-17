#include<iostream>
#include<malloc.h>
using namespace std;

int firstMissingPositive(int* nums, int numsSize) {
	int a;
	bool b = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (!(nums[i] < 1 || nums[i]>numsSize || nums[i] == i)) {
			if (nums[i] == numsSize)
				b = 1;
			else {
				a = nums[i];
				if (a > i&& nums[a] != a) {
					nums[i] = nums[a];
					nums[a] = a;
					--i;
					continue;
				}
				else
					nums[a] = a;
			}
			nums[i] = 0;
		}
	}
	for (int i = 1; i < numsSize; ++i)
		if (nums[i] < 1 || nums[i]>numsSize)
			return i;
	if (b)
		return numsSize + 1;
	else return numsSize;
	return 0;
}
int main() {
	int s[] = { 2,2 };

	cout << firstMissingPositive(s, 2);
	cout << " a";
}

