#include<iostream>
using namespace std;
int longestValidParentheses(char * s) {
	int i=0,l=0,r;
	int ynn=0,zn=0;
	int big=0;
	while(s[i]!='\0') {
		if(s[i++]=='(') {
			++ynn;
			++zn;
		} else
			--zn;
		if(zn<0) {
			if(ynn>big) big=ynn;
			zn=0;
			ynn=0;
			l=i;
		}
	}
	ynn=0;
	zn=0;
	for(int r=i-1; r>=l; r--) {
		if(s[r]==')') {
			++zn;
			++ynn;
		}
		else
			--zn;
		if(zn<0) {
			if(ynn>big) big=ynn;
			ynn=0;
			zn=0;
		}
	}
	if(ynn>big) big=ynn;
	return big*2;
}
int main() {
//	char s[17]= {'(',')','(',')','(','(','(',')',')','(',')','(','(',')','(',')'};
	char s[6]= {'(',')','(','(',')'};
	cout<<longestValidParentheses(s);
}
