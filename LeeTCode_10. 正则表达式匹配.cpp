#include<iostream>
#include<malloc.h>
using namespace std;

bool isMatch(char* s, char* p) {
	if (p[0] == '*')return false;
	int s_lenght = 0;
	int p_lenght = 0;
	while (s[s_lenght++] != '\0');
	while (p[p_lenght++] != '\0');
	for (int i = 1; i < p_lenght; ++i)
		if (p[i] == '*' && p[i - 1] == '*')return false;
	bool** b = (bool**)malloc(sizeof(bool*) * 2);
	for (int i = 0; i < 2; ++i)
		b[i] = (bool*)malloc(sizeof(bool) * p_lenght);
	b[0][0] = true;
	for (int i = 1; i < p_lenght; ++i)
		if (p[i - 1] == '*')
			b[0][i] = b[0][i - 2];
		else
			b[0][i] = false;
	for (int i = 1; i < s_lenght; ++i) {
		b[i % 2][0] = false;
		for (int j = 1; j < p_lenght; ++j)
			if (p[j - 1] == '*' && (b[i % 2][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && b[(i - 1) % 2][j])
				|| (s[i - 1] == p[j - 1] || p[j - 1] == '.') && b[(i - 1) % 2][j - 1])
				b[i % 2][j] = true;
			else
				b[i % 2][j] = false;
	}
	return b[(s_lenght + 1) % 2][p_lenght - 1];
}
int main() {
	char s[] = { 'a','a','\0' };
	char p[] = { 'a','*','\0' };
	cout << isMatch(s, p);
}
