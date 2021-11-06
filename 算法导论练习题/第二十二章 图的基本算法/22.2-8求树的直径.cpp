#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef struct as {
	struct as *next;
	int val;
} V;
typedef struct zx {
	bool b;
	int len;
} jd;
typedef struct ddd {
	int head;
	int wei;
	int num;
	int lenght;
	int *data;
} DUI;
DUI *duiinit(int lenght) {
	DUI *q=(DUI*)malloc(sizeof(DUI));
	q->head=0;
	q->num=0;
	q->wei=0;
	q->lenght=lenght;
	q->data=(int *)malloc(sizeof(int)*lenght);
	return q;
}
void ru(DUI *q,int val) {
	q->data[q->wei]=val;
	q->wei++;
	if(q->wei==q->lenght)q->wei=0;
	q->num++;
}
int chu(DUI *q) {
	int a=q->data[q->head];
	q->num--;
	q->head++;
	if(q->head==q->lenght) q->head=0;
	return a;
}
V** cjlb(int lenght) {
	V **q=(V **)malloc(sizeof(V *)*(lenght+1));
	memset(q,0,sizeof(V *)*(lenght+1));
	return q;
}
void addlb(V **q,int a,int b,bool boo) {
	V *z=(V *)malloc(sizeof(V));
	z->next=q[a];
	z->val=b;
	q[a]=z;
	if(boo) {
		z=(V *)malloc(sizeof(V));
		z->next=q[b];
		z->val=a;
		q[b]=z;
	}
}
int lbdfsc(V **q,int val1,int lenght,int *len) {//链表矩阵广搜 
	int val=val1;
	DUI *dui=duiinit(lenght);
	jd *z=(jd *)malloc(sizeof(jd)*(lenght+1));
	memset(z,0,sizeof(jd)*(lenght+1));
	z[val].b=1;
	ru(dui,val);
	int v;
	while(dui->num) {
		v=chu(dui);
		V *a=q[v];
		while(a) {
			if(!z[a->val].b) {
				z[a->val].b=true;
				z[a->val].len=z[v].len+1;
				ru(dui,a->val);
			}
			a=a->next;
		}
	}
	*len=z[v].len;
	return  v;
}

int **cjjz(int lenght) {
	int **q=(int **)malloc(sizeof(int *)*(lenght+1));
	for(int i=0; i<=lenght; ++i) {
		q[i]=(int *)malloc(sizeof(int)*(lenght+1));
		memset(q[i],0,sizeof(int)*(lenght+1));
	}
	return q;
}
void addjz(int **q,int a,int b,bool boo) {
	q[a][b]=1;
	if(boo)q[b][a]=1;
}
int jzdfs(int **q,int val,int lenght,int *len) {//矩阵矩阵广搜 
	DUI *dui=duiinit(lenght);
	jd *a=(jd*)malloc(sizeof(jd)*(lenght+1));
	memset(a,0,sizeof(jd)*(lenght+1));
	a[val].b=true;
	ru(dui,val);
	int nn;
	while(dui->num) {
		nn=chu(dui);
		for(int i=1; i<=lenght; ++i) {
			if(q[nn][i]&&!a[i].b) {
				a[i].b=true;
				a[i].len=a[nn].len+1;
				ru(dui,i);
			}
		}
	}
	*len=a[nn].len;
	return  nn;
}
void *cj(int lenght,int n) {
	if(n==1) return cjlb(lenght);
	return cjjz(lenght);
}
void add(void *q,int a,int b,int n,bool boo) {
	if(n==1)addlb((V **)q,a,b,boo);
	else addjz((int **)q,a,b,boo);
}
int tuzhijin(void *q,int n,int lenght){//求树的直径 时间复杂度为广搜的时间 
	int len1,num,len2;
	if(n==1){
		len1=lbdfsc((V **)q,1,lenght,&num);
		len2=lbdfsc((V **)q,len1,lenght,&num);
	}else{
		len1=jzdfs((int **)q,1,lenght,&num);
		len2=jzdfs((int **)q,len1,lenght,&num);
	}
	printf("结点为：%d  %d    ",len1,len2);
	return num;
}
int main(){
	while(1){
		printf("输入树结点 1：链表，2：矩阵 1：无向图，0：有向图\n");
		int lenght,n,boo;
		scanf("%d%d%d",&lenght,&n,&boo);
		void *q=cj(lenght,n);
		printf("输入树边数，图边\n");
		int c;
		scanf("%d",&c);
		for(int i=0;i<c;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			add(q,u,v,n,boo);
		}
		printf("距离为%d\n",tuzhijin(q,n,lenght));
	}
}
