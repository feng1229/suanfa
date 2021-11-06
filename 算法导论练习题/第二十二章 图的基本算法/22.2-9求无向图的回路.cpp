#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct D {
	int head;
	int num;
	int lenght;
	int wei;
	int *data;
} DUI;
void ru(DUI *dui,int val) {
	dui->data[dui->wei]=val;
	dui->wei++;
	if(dui->wei==dui->lenght)dui->wei=0;
	dui->num++;
}
int chu(DUI *dui) {
	int q=dui->data[dui->head];
	dui->num--;
	dui->head++;
	if(dui->head==dui->lenght)dui->head=0;
	return q;
}
DUI *initdui(int lenght) {
	DUI *q=(DUI *)malloc(sizeof(DUI));
	q->data=(int *)malloc(sizeof(int )*(lenght+1));
	q->head=0;
	q->num=0;
	q->wei=0;
	return q;
}
typedef  struct  VV {
	struct VV *next;
	int val;
} V;
void addlb(V **q,int a,int b) {
	V *z=(V *)malloc(sizeof(V));
	z->next=q[a];
	z->val=b;
	q[a]=z;
}
void *initlb(int lenght) {
	V **q=(V **)malloc(sizeof(V *)*(lenght+1));
	memset(q,0,sizeof(V *)*(lenght+1));
	return q;
}

V *lb(V **q,int val,int lenght) { //链表求无向图回路，时间复杂度为V+E
	V *ret=(V *)malloc(sizeof(V));
	ret->val=val;
	ret->next=NULL;
	V **as=(V**)malloc(sizeof(V*)*(lenght+1));
	as[val]=ret;
	int *z=(int *)malloc(sizeof(int)*(lenght+1));
	memset(z,0,sizeof(int)*(lenght+1));
	z[val]=true;
	DUI *dui=initdui(lenght);
	ru(dui,val);
	while(dui->num) {
		int c=chu(dui);
		ret=as[c];
		V *v=q[c];
		V *a2;
		while(v) {
			if(z[v->val]!=2) {
				V *a1=(V *)malloc(sizeof(V));
				a2=(V *)malloc(sizeof(V));
				a1->val=c;
				a2->val=v->val;
				a1->next=ret->next;
				a2->next=a1;
				ret->next=a2;
				if(z[v->val]==0) {
					ru(dui,v->val);
					as[v->val]=a2;
				} else {
					z[v->val]=1;
				}
			}
			v=v->next;
		}
		z[c]=2;
	}
	return as[val];
}
int  main() {
	while(1) {
		printf("输入无向图结点个数，边数，边\n");
		int lenght,bian;
		scanf("%d%d",&lenght,&bian);
		void *q=initlb(lenght);
		for(int i=0; i<bian; ++i) {
			int a,b;
			scanf("%d%d",&a,&b);
			addlb((V **)q,a,b);
			addlb((V **)q,b,a);
		}
		V *aaa=lb((V **)q,1,lenght);
		while(aaa) {
			printf("%d ",aaa->val);
			aaa=aaa->next;
		}
		printf("\n");
	}
}
