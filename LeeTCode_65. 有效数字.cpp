#include<iostream>
#include<malloc.h>
using namespace std;

bool isNumber(char* s) {
	bool sz = 0, be = 0, bd = 0;
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '+' || s[i] == '-') {
			if (sz || (i > 0 && s[i-1] == '.'))
				return false;
		}
		else
			if (s[i] == 'e'|| s[i] == 'E') {
				if (!sz || be)return false;
				be = 1;
				sz = 0;
				bd = 1;
			}
			else
				if (s[i] == '.') {
					if (bd)return false;
					bd = 1;
				}
				else
					if (s[i] < 0x30 || s[i]>0x39)
						return false;
					else
						sz = 1;
		++i;
	}
	if (!sz)return false;
	return true;
}
int main() {
	char s[] = { '1','e','+','\0' };
	cout << isNumber(s);
}
