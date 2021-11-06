#include<stdio.h>
#include<malloc.h>

char c[5]= {' ',' ','S','B','Q'};
char *a;
int ii=1;
int zd(int n,int i,int w) {
	if(i<5) {
		if(!w) {
			if(n==0)
				a[ii++]='0';
			return 1;
		} else {
			if(i>1)
				a[ii++]=c[i];
			a[ii++]=w+'0';
			return 0;
		}
	} else {
		if(!w) {
			if(n==2)
				a[ii++]='0';
			return n;
		} else {
			i-=4;
			if(i>1) a[ii++]=c[i];
			a[ii++]=w+'0';
			return 2;
		}
	}
}
int main() {
	a=(char *)malloc(sizeof(char)*20);
	int q;
	scanf("%d",&q);
	int i=0,n=1;
	do {
		++i;
		int w=q%10;
		if(i==5) {
			a[ii++]='W';
		} else if(i==9) {
			i=1;
			if(n==1) a[ii-1]='Y';
			else {
				if(n==0) a[ii-1]='0';
				a[ii++]='Y';
			}
		}
		n=zd(n,i,w);
		q=q/10;
	} while(q);
	--ii;
	for(; ii>0; ii--)printf("%c",a[ii]);
}
