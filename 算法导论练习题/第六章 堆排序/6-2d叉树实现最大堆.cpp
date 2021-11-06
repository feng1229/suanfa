#include<stdio.h>
#include<stdlib.h>

#define P(x) ((x+d-2)/d)
#define LEFT(x) (x*d-d+2)
#define swap(x,y)\
	int qq=*x;\
	*x=*y;\
	*y=qq;

int d;
void add(int *a,int len,int key) { //加入，时间复杂度为：logdn。
	int p=len;
	while(a[P(p)]<key) {
		a[p]=a[P(p)];
		p=P(p);
	}
	a[p]=key;
}
void weihu(int *a,int ii,int len) {
	int max=ii;
	int i=ii;
	do {
		i=max;
		int l=LEFT(max);
		for(int z=0; z<d; ++z) {
			if(l+z<=len)max=(a[l+z]>a[max])?l+z:max;
		}
		if(i!=max) {
			swap(&a[max],&a[i]);
		}
	} while(i!=max);
}
int maxdet(int *a,int len) { //提取最大值，时间复杂度为： dlogdn，
	int q=a[1];
	a[1]=a[len];
	weihu(a,1,len-1);
	return q;
}
int gengai(int *a,int i,int x) { //时间复杂度为：logdn
	if(x<a[i]) return -1;
	int p=i;
	while(a[P(p)]<x) {
		a[p]=a[P(p)];
		p=P(p);
	}
	a[p]=x;
	return 0;
}
int main() {
	d=4;
	int *a=(int *)malloc(sizeof(int)*1000);
	a[0]=0x7FFFFFFF;
	int lenght=0;
	printf("1：加入，2：最大值：3更改（i，key）。\n");
	int c,n;
	do {
		scanf("%d",&c);
		switch(c) {
			case 1:
				scanf("%d",&n);
				for(int i=0; i<n; ++i) {
					scanf("%d",&c);
					add(a,++lenght,c);
				}
				break;
			case 2:
				for(; lenght>0; --lenght) {
					printf("%d ",maxdet(a,lenght));
				}
				printf("\n");
				break;
			case 3:
				scanf("%d%d",&c,&n);
				gengai(a,c,n);
				break;
		}
	} while(1);
}

