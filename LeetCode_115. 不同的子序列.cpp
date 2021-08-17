#include<iostream>
#include<malloc.h>
using namespace std;
int numDistinct(char* s, char* t) {
	int s_lenght = -1, t_lenght = -1;
	short zm[138] = { 0 };
	while (t[++t_lenght] != '\0');
	unsigned int* n = (unsigned int*)malloc(sizeof(unsigned int) * (t_lenght + 1));
	short* tt = (short*)malloc(sizeof(short) * (t_lenght + 1));
	tt[0] = 0;
	n[0] = 1;
	for (int i = 1; i < t_lenght + 1; ++i)
		n[i] = 0;
	for (int i = 0; i < t_lenght;) {
		int j = t[i];
		++i;
		tt[i] = zm[j];
		zm[j] = i;
	}
	while (s[++s_lenght] != '\0') {
		int i = zm[s[s_lenght]];
		while (i) {
			n[i] += n[i - 1];
			i = tt[i];
		}
	}
	return n[t_lenght];
}
int main() {
	char s[] = { 'a','a','a','b','b','a','a','a','a','b','b','b','a','a','a','a','b','a','\0' };
	char t[] = { 'a','b','b','a','\0' };
	cout << numDistinct(s, t);
}
