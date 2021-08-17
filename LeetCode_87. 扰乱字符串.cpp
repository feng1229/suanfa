#include<iostream>
#include<malloc.h>
using namespace std;
short zm[26] = { 1000,2037,3078,4124,5168,6221,7280,8341,9408,10479,11552,12631,13714,14803,15900,17001,18104,19211,20320,21433,22560,23691,24828,25967,27116,28267 };
bool you(char*, char*, short);
bool zuo(char* s, char* t, short r) {
	short* stack = (short*)malloc(sizeof(short*) * (r + 1));
	short top = 0;
	stack[0] = -1;
	int sn = 0, tn = 0;
	bool bl = false;
	for (int i = 0; i < r; ++i) {
		sn += zm[s[i] - 'a'];
		tn += zm[t[i] - 'a'];
		if (sn == tn) {
			if (i - stack[top] > 3) {
				if (i != r - 1)
					bl = you(&s[stack[top] + 1], &t[stack[top] + 1], i - stack[top]);
				else {
					int k = top;
					while (!bl && k > -1) {
						if (k == 0) {
							free(stack);
							return false;
						}
						bl = you(&s[stack[k] + 1], &t[stack[k] + 1], i - stack[k]);
						--k;
					}
				}
			}
			else
				bl = true;
			if (bl) {
				stack[++top] = i;
				bl = false;
			}
			sn = 0;
			tn = 0;
		}
	}
	bl = stack[top] == r - 1;
	free(stack);
	return bl;
}
bool you(char* s, char* t, short r) {
	short* stack = (short*)malloc(sizeof(short*) * (r + 1));
	short top = 0;
	stack[0] = -1;
	int sn = 0, tn = 0;
	bool bl = false;
	for (int i = 0; i < r; ++i) {
		sn += zm[s[i] - 'a'];
		tn += zm[t[r - i - 1] - 'a'];
		if (sn == tn) {
			if (i - stack[top] > 3) {
				if (i != r - 1)
					bl = zuo(&s[stack[top] + 1], &t[r - i - 1], i - stack[top]);
				else {
					int k = top;
					while (!bl && k > -1) {
						if (k == 0) {
							free(stack);
							return false;
						}
						bl = zuo(&s[stack[k] + 1], &t[r - i - 1], i - stack[k]);
						--k;
					}
				}
			}
			else
				bl = true;
			if (bl) {
				stack[++top] = i;
				bl = false;
			}
			sn = 0;
			tn = 0;
		}
	}
	bl = stack[top] == r - 1;
	free(stack);
	return bl;
}
bool isScramble(char* s1, char* s2) {
	int lenght = -1;
	while (s1[++lenght] != '\0');
	int sn = 0, tn = 0;
	for (int i = 0; i < lenght; ++i) {
		sn += zm[s1[i] - 'a'];
		tn += zm[s2[i] - 'a'];
	}
	if (sn != tn)return false;
	if (lenght < 4)return true;
	bool b = false;
	b = zuo(s1, s2, lenght);
	if (b) return true;
	return you(s1, s2, lenght);
}

int main() {
	char s[] = { 'a','b','c','d','b','d','a','c','b','d','a','c','\0' };
	char t[] = { 'b','d','a','c','a','b','c','d','b','d','a','c','\0' };
	cout << isScramble(s, t);
}
