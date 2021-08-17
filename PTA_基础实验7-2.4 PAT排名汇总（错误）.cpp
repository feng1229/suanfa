#include<stdio.h>
#include<stdlib.h>
#define MAX 30000
typedef struct {
	long long kh;
	int zcj;//成绩
	int kc;//考场
	int bcj;//考场排名
} student;
student **fuzhu;
int *e;
int *ee;
int kppx(student **,int ,int );
void kp(student **,int ,int );
void zhongpx(student **,int,int);
void px(student **,int ,int );
void paixu(student **,int ,int ,int );
void crpaixu(student **,int ,int );
int main() {
	fuzhu=(student **)malloc(sizeof(student *)*MAX);
	int N,K,num=0;
	student ***n;
	student **zhong;
	scanf("%d",&N);
	n=(student ***)malloc(sizeof(student **)*N);
	e=(int*)malloc(sizeof(int)*N);
	ee=(int*)malloc(sizeof(int)*N);
	for(int i=0; i<N; i++) {
		scanf("%d",&K);
		e[i]=K;
		num+=K;
		ee[i]=num;
		n[i]=(student **)malloc(sizeof(student *)*K);
		for(int j=0; j<K; j++) {
			student *s=(student *)malloc(sizeof(student));
			s->kc=i+1;
			scanf("%lld %d",&s->kh,&s->zcj);
			n[i][j]=s;
		}
		px(n[i],0,K-1);
		n[i][0]->bcj=1;
		for(int j=1; j<K; j++) {
			if(n[i][j]->zcj==n[i][j-1]->zcj)
				n[i][j]->bcj=n[i][j-1]->bcj;
			else
				n[i][j]->bcj=j+1;
		}
	}
	zhong=(student **)malloc(sizeof(student *)*num);
	int number=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<e[i]; j++)
			zhong[number++]=n[i][j];
	zhongpx(zhong,0,N-1);

	printf("%d\n",num);
	for(int i=0; i<num; i++) {
		int c=0;
		while(i+c+1<num&&zhong[i]->zcj==zhong[i+c+1]->zcj)
			c++;
		if(c>0) {
			kp(zhong,i,i+c);
			for(int j=0; j<=c; j++)
				printf("%lld %d %d %d\n",zhong[i+j]->kh,i+1,zhong[i+j]->kc,zhong[i+j]->bcj);
			i+=c;
		} else
			printf("%lld %d %d %d\n",zhong[i]->kh,i+1,zhong[i]->kc,zhong[i]->bcj);
	}
	return 0;
}
void zhongpx(student **a,int l,int r) {
	if(l<r) {
		int q=(r+l)/2;
		zhongpx(a,l,q);
		zhongpx(a,q+1,r);
		paixu(a,ee[l]-e[l],ee[q]-1,ee[r]-1);
	}
}
void px(student **a,int l,int r) {
	if(l<r) {
		int q=(r+l)/2;
		px(a,l,q);
		px(a,q+1,r);
		paixu(a,l,q,r);
	}
}
void paixu(student **a,int l,int q,int r) {
	for(int i=0; i<=q-l; i++) fuzhu[i]=a[l+i];
	int k=0,li=0,ri=1;
	while(k<=r-l) {
		if(ri>r-q||(li<=q-l&&fuzhu[li]->zcj>a[q+ri]->zcj))
			a[l+k]=fuzhu[li++];
		else
			a[l+k]=a[q+ri++];
		k++;
	}
}
void kp(student **a,int l,int r){
	if(l<r){
		int q=kppx(a,l,r);
		kp(a,l,q-1);
		kp(a,q+1,r);
	}
}
int kppx(student **a,int l,int r) {
	long long sl=a[r]->kh;
	int k=l;
	for(int i=l; i<r; i++) {
		if(a[i]->kh<sl) {
			student *s=a[i];
			a[i]=a[k];
			a[k]=s;
			k++;
		}
	}
	student *s=a[r];
	a[r]=a[k];
	a[k]=s;
	return k;
}

void crpaixu(student **a,int l,int r) {
	for(int i=l+1; i<=r; i++) {
		student *s=a[i];
		int j=i-1;
		while(j>=l&&s->kh<a[j]->kh) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=s;
	}
}

