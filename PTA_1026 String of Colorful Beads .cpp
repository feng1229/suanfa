#include<stdio.h>
#include<stdlib.h>

int *v,*shuru,*fuzhu,*num;
int N,left,right,l=0,number=0,lenght=0;
void init() ;
int main() {
	scanf("%d",&N);
	v=(int *)malloc(sizeof(int)*N);
	shuru=(int *)malloc(sizeof(int)*N);
	fuzhu=(int *)malloc(sizeof(int)*(N+1));
	num=(int *)malloc(sizeof(int)*(N+1));
	for(int i=0; i<=N; i++)fuzhu[i]=0;
	num[0]=0;
	for(int i=0; i<N; i++)scanf("%d",&v[i]);
	for(int i=0; i<N; i++)scanf("%d",&shuru[i]);

	init();
	printf("%d %d %d",number,left,right);
}
void init() {
	int i_i;
	for(int i=0; i<N; i++) {
		i_i=shuru[i];
		num[i+1]=v[i_i-1]+num[i];
		if(fuzhu[i_i]!=0&&fuzhu[i_i]>l) {
			if(i-l>lenght) {
				left=l;
				right=i-1;
				lenght=i-l;
				number=num[i]-num[l];
			} else if(i-l==lenght&&num[i]-num[l]>number) {
				left=l;
				right=i-1;
				number=num[i]-num[l];
			}
			l=fuzhu[i_i];
		}
		fuzhu[i_i]=i+1;
	}
	if(N-l>lenght) {
		left=l;
		right=N-1;
		number=num[N]-num[l];
	} else if(N-l==lenght&&num[N]-num[l]>number) {
		left=l;
		right=N-1;
		number=num[N]-num[l];
	}
}
