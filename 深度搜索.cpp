#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MM 100

int *w;int tt=MM;
int time=0;
typedef struct qqq{
	int p;
	int d;
	int f;
	int cloor;
}*G,g;
typedef struct aa{
	struct aa *next;
	int k;
}*abj,ll;
abj* init(){
	abj *a=(abj*)malloc(sizeof(abj)*MM);
	srand(MM);
	for(int i=0;i<MM;++i){
		abj m=(abj)malloc(sizeof(ll));
		a[i]=m;
		a[i]->k=i;
		for(int j=0;j<1;++j){
			abj p=(abj)malloc(sizeof(ll));
			p->k=rand()%MM;
			m->next=p;
			m=p;
		}
		m->next=NULL;
	}
	return a;
}
void shen(G q,int n,abj *a){
	++time;
	q[n].d=time;
	q[n].cloor=1;
	abj m=a[n]->next;
	while(m){
		if(!q[m->k].cloor){
			q[m->k].p=n;
			shen(q,m->k,a);
		}
		m=m->next;
	}
	w[--tt]=n;
	++time;
	q[n].cloor=2;
	q[n].f=time;
}
int main(){
	w=(int *)malloc(sizeof(int )*MM);
	abj *a=init();
	G q=(G)malloc(sizeof(g)*MM);
	for(int i=0;i<MM;++i){
	q[i].p=-1;
	q[i].cloor=0;}
	for(int i=0;i<MM;++i){
		if(!q[i].cloor) shen(q,i,a);
	}
	int p=16;	
	while(p!=-1){
		printf("%d ",p);
		p=q[p].p;
	}	 
	printf("\n");
	for(int i=0;i<MM;++i)printf("%d ",w[i]);
} 
