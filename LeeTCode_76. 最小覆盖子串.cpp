#include<iostream>
#include<malloc.h>
using namespace std;

char* minWindow(char* s, char* t) {
	int s_lenght = -1;
	int t_lenght = -1;
	while (s[++s_lenght] != '\0');
	while (t[++t_lenght] != '\0');
	int l = 0, r = 0, num = 0, min = 20001, lz = 0;
	int zimu[58] = { 0 };
	int n[58] = { 0 };
	for (int i = 0; i < t_lenght; ++i)
		++zimu[t[i] - 'A'];
	for (; r < s_lenght; ++r) {
		num += (n[s[r] - 'A'] < zimu[s[r] - 'A']);
		++n[s[r] - 'A'];
		while (num == t_lenght) {
			lz += (r - l < min) * (l - lz);
			min = (r - l < min) ? r - l : min;
			--n[s[l] - 'A'];
			num -= (n[s[l] - 'A'] < zimu[s[l] - 'A']);
			++l;
		}
	}
	char* qq;
	int j = 0, g = 0;
	g = (min < 20001) * (min + 1);
	qq = (char*)malloc(sizeof(char) * (g + 1));
	for (; j < g; ++j)
		qq[j] = s[lz + j];
	qq[g] = '\0';
	return qq;
}
int main() {
	char s[] = { 'A','D','O','z','E','C','O','D','E','B','A','N','z','\0' };
	char p[] = { 'A','z','z','\0' };
	char* a = minWindow(s, p);
	cout << a;
}
