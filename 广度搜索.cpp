#include<stdio.h>
#include<malloc.h>
#define SHU 100

typedef struct G {
	int p;
	int d;
	int b;
} g,*g_p;

typedef struct V {
	int n;
	struct V *next;
} v,*v_p;

typedef struct dp {
	int *d;
	int l;
	int lenght;
	int head;
	int wei;
} Q;
Q* init_dui() {
	Q *q=(Q*)malloc(sizeof(Q));
	q->lenght=100;
	q->d=(int *)malloc(sizeof(int)*q->lenght);
	q->head=0;
	q->wei=0;
	q->l=0;
	return q;
}
v_p* init() {
	v_p *a=(v_p*)malloc(sizeof(v_p)*SHU);
	for(int i=0; i<SHU-4; ++i) {
		v_p m=(v_p)malloc(sizeof(v));
		a[i]=m;
		a[i]->n=i;		
		for(int j=1; j<5; ++j) {
			v_p q=(v_p)malloc(sizeof(v));
			m->next=q;
			q->n=i+j;
			m=q;
		}
		m->next=NULL;
	}
	for(int i=SHU-4; i<SHU; ++i) {
		a[i]=(v_p)malloc(sizeof(v));
		a[i]->n=i;
		a[i]->next=NULL;
	}
	return a;
}

bool add(Q *q,int z) {
	if(q->l<q->lenght) {
		q->d[q->wei]=z;
		q->wei++;
		if(q->wei==q->lenght)
			q->wei=0;
		q->l++;
		return true;
	} else return false;
}
int det(Q *q) {
	if(q->l>0) {
		int n=q->d[q->head];
		q->head++;
		if(q->head==q->lenght)
			q->head=0;
		q->l--;
		return n;
	} else return -1;
}
int len(Q *q){
	return q->l;
}

int main() {
	Q *q=init_dui();
	v_p *head=init();
	add(q,0);
	g_p gp=(g_p)malloc(sizeof(g)*SHU);
	for(int i=0;i<SHU;++i){
		gp[i].b=0;
	}
	gp[0].d=0;
	gp[0].b=1;
	while(len(q)){
		int i=det(q);
		v_p m=head[i];
		int d=gp[i].d;
		while(m=m->next){
			int n=m->n;
			if(!gp[n].b){
				gp[n].b=1;
				gp[n].d=d+1;
				add(q,n);
				gp[n].p=i;
			}
		}
	}
	int z=gp[SHU-2].p;
	while(z){
		printf("%d ",z);
		z=gp[z].p;
	}
}














