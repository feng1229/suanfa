#include<iostream>
#include<malloc.h>
using namespace std;
#define yu(x) (x)&0x1
#define min(x,y,z) \
((x<y)?((x<z)?x:z):((y<z)?y:z))

int minDistance(char* word1, char* word2) {
	int s_lenght = -1;
	int p_lenght = -1;
	while (word1[++s_lenght] != '\0');
	while (word2[++p_lenght] != '\0');
	int** b = (int**)malloc(sizeof(int*) * 2);
	b[0] = (int*)malloc(sizeof(int) * (p_lenght + 1));
	b[1] = (int*)malloc(sizeof(int) * (p_lenght + 1));
	for (int i = 0; i <= p_lenght; i++)
		b[0][i] = i;
	for (int i = 0; i < s_lenght; ++i) {
		b[yu(i + 1)][0] = i + 1;
		for (int j = 0; j < p_lenght; ++j)
			b[yu(i + 1)][j + 1] = (min(b[yu(i)][j], b[yu(i)][j + 1], b[yu(i + 1)][j]) + 1) * (word1[i] != word2[j]) + b[yu(i)][j] * (word1[i] == word2[j]);
	}
	return b[yu(s_lenght)][p_lenght];
}
int main() {
	char s[] = { 'h','o','r','s','e','\0' };
	char p[] = { 'r','o','s','\0' };
	cout << minDistance(s, p);
}
