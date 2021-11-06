#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int lenght;

struct DUI {
	int n;
	int k;
	int len;
	int *data;
};

struct DUI* cjd(int n) {
	struct DUI *q=(struct DUI*)malloc(sizeof(struct DUI));
	q->n=0;
	q->k=0;
	q->len=n;
	q->data=(int *)malloc(sizeof(int)*n);
	return q;
}
int rudui(struct DUI *dui,int a) {
	dui->data[(dui->k+dui->n)%dui->len]=a;
	dui->n++;
	return 0;
}
int chudui(struct DUI *dui) {
	if(!dui->n)return 0;
	int q=dui->data[dui->k];
	dui->k=(dui->k+1)%dui->len;
	dui->n--;
	return q;
}
struct V {
	struct V *next;
	int val;
};

struct P {
	int p;
	bool s;
};
int addlb(struct V **q,int a,int b) {//加入邻接链表
	if(a>lenght||b>lenght)return -1;
	struct V *w=(struct V*)malloc(sizeof(struct V));
	w->val=b;
	w->next=q[a];
	q[a]=w;
	return 0;
}

void lbbfs(struct V **q,int i) {//邻接链表广度搜索。时间复杂度为V+E
	struct DUI *dui=cjd(lenght);
	struct P* a=(struct P*)malloc(sizeof(struct P)*(lenght+1));
	memset(a,0,sizeof(struct P)*(lenght+1));
	a[i].s=true;
	rudui(dui,i);
	while(dui->n) {
		int val=chudui(dui);
		printf("%d ",val);
		struct V *w=q[val];
		while(w) {
			if(!a[w->val].s) {
				a[w->val].s=true;
				a[w->val].p=val;
				rudui(dui,w->val);
			}
			w=w->next;
		}
	}
}

struct V** konglb() {
	struct V **q=(struct V**)malloc(sizeof(struct V*)*(lenght+1));
	memset(q,0,sizeof(struct V*)*(lenght+1));
	return q;
}
int **kongjz() {
	int **q=(int **)malloc(sizeof(int *)*(lenght+1));
	for(int i=0; i<=lenght; ++i) {
		q[i]=(int *)malloc(sizeof(int)*(lenght+1));
		memset(q[i],0,sizeof(int)*(lenght+1));
	}
	return q;
}
void addjz(int **q,int a,int b) {
	q[a][b]=1;
}
void jzbfs(int **q,int val) {//邻接矩阵广度搜索。时间复杂度为 V*V
	struct P *a=(struct P*)malloc(sizeof(struct P)*(lenght+1));
	memset(a,0,sizeof(struct P)*(lenght+1));
	struct DUI *dui=cjd(lenght);
	a[val].s=true;
	rudui(dui,val);
	while(dui->n) {
		int val=chudui(dui);
		printf("%d ",val);
		for(int i=1; i<=lenght; ++i) {
			if(q[val][i]&&(!a[i].s)) {
				a[i].s=true;
				a[i].p=val;
				rudui(dui,i);
			}
		}
	}
}
void *cj(int n) {
	void *q;
	if(n==1)q=konglb();
	else q=kongjz();
	return q;
}
void add(void *q,int a,int b,int n) {
	if(n==1)addlb((struct V**)q,a,b);
	else addjz((int **)q,a,b);
}
void bl(void *q,int i,int n){
	if(n==1){
		lbbfs((struct V**)q,i);
	}else jzbfs((int **)q,i);
}
int main() {
	while(1) {
		int c;
		printf("输入结点个数，1（链表）或2（矩阵）\n");
		scanf("%d %d",&lenght,&c);
		void *q=cj(c);
		printf("输入边数，后跟边\n");
		int nn;
		scanf("%d",&nn);
		for(int i=0; i<nn; ++i) {
			int u,v;
			scanf("%d %d",&u,&v);
			add(q,u,v,c);
		}
		bl(q,2,c);
		printf("\n"); 
	}
}


//10 2 1 2 6 6 3 6 7 1 5 3 4 7 8 3 7 4 7 4 8



