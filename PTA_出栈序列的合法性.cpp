#include<stdio.h>
#include<stdlib.h>

int main() {
	int M,N,K;
	scanf("%d %d %d",&M,&N,&K);
	int *m=(int *)malloc(sizeof(int)*N);
	int *vis=(int *)malloc(sizeof(int)*(N+2));
	for(int i=0; i<K; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d",&m[j]);
			vis[j]=j-1;
		}
		vis[N]=N-1;
		int num=0;
		int big=0;
		int q=1;
		for(int j=0; j<N; j++) {
			if(m[j]-big>M-num) {
				q=0;
				break;
			}
			if(m[j]>big) {
				vis[m[j]+1]=vis[m[j]];
				num+=m[j]-big-1;
				big=m[j];
			} else {
				if(m[j]!=vis[big+1]) {
					q=0;
					break;
				}
				vis[big+1]=vis[m[j]];
				num--;
			}
		}
		if(q)printf("YES\n");
		else printf("NO\n");
	}
}
