#include<iostream>
#include<malloc.h>
#define qu(x) ((x)%2)
using namespace std;
bool isMatch(char* s, char* p) {
	int s_lenght =0;
	int p_lenght =0;
	while (s[s_lenght++] != '\0'); cout << s_lenght;
	while (p[p_lenght++] != '\0'); cout << p_lenght;
	bool** b = (bool**)malloc(sizeof(bool*) * 2);
	b[0] = (bool*)malloc(sizeof(bool) * p_lenght);
	b[1] = (bool*)malloc(sizeof(bool) * p_lenght);
	b[0][0] = true;
	b[1][0] = 0;
	for (int i = 1; i < p_lenght; ++i)
		if (p[i-1] != '*')b[0][i] = false;
		else b[0][i] = b[0][i - 1];
	for (int i = 1; i < s_lenght; ++i) {
		for (int j = 1; j < p_lenght; ++j) {
			cout << b[qu(i - 1)][j - 1] << " " << b[qu(i)][j - 1] << " <" << b[qu(i - 1)][j] << endl;
			if ((s[i - 1] == p[j - 1] || p[j - 1] == '?') && b[qu(i - 1)][j - 1]
				|| p[j - 1] == '*' && (b[qu(i)][j - 1] || b[qu(i - 1)][j]))
				b[qu(i)][j] = true;
			else
				b[qu(i)][j] = false;
		}
		b[0][0] = false;
	}
	return b[qu(s_lenght + 1)][p_lenght - 1];	
}
int main() {
	char a[] = { 'a','a','\0' };
	char b[] = { '*','\0'};
	cout<<isMatch(a, b);
}

