#include<stdio.h>
#include<stdlib.h>
void paixu(int a[],int d[],int l[],int c,int i);
int main() {
	int N;
	int max=0;
	int P,L,D;
	scanf("%d",&N);
	int **V=(int **)malloc(sizeof(int *)*(N+1));
	int *p=(int *)malloc(sizeof(int )*(N+1));
	int *l=(int *)malloc(sizeof(int )*(N+1));
	int *d=(int *)malloc(sizeof(int )*(N+1));
	int *px=(int *)malloc(sizeof(int )*(N+1));
	for(int i=0; i<N; i++) {
		scanf("%d %d %d",&P,&L,&D);
		if(L>D||P<=0||D<=0||N>50)return 0;
		if(D>max)max=D;
		p[i+1]=P;
		l[i+1]=L;
		d[i+1]=D;
		paixu(px,d,l,D,i);
	}
	for(int i=0; i<=N; i++) {
		V[i]=(int *)malloc(sizeof(int)*(max+1));
		V[i][0]=0;
	}
	for(int i=0; i<=max; i++)
		V[0][i]=0;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=max; j++) {
			int y=px[i];
			int min;
			min=(d[y]<j)?d[y]:j;
			int k=min-l[y];
			if(k<0)
				V[i][j]=V[i-1][j];
			else {
				int h=V[i-1][k]+p[y];
				V[i][j]=(V[i-1][j]>h)?V[i-1][j]:h;	
			}
		}
	printf("%d",V[N][max]);
}
void paixu(int a[],int d[],int l[],int c,int i) {
	int k=i+1;
	while(i>=1&&c<d[a[i] ]){
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=k;
}
