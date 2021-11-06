#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int lenght;
typedef struct VV{
	struct VV *next;
	int val;
}V;

typedef struct D{
	int head;
	int wei;
	int n;
	int lenght;
	int *data;
}dui;

typedef struct SS{
	int p;
	int d;
	bool b;
}jd;

dui *cj(int lenght){
	dui *q=(dui *)malloc(sizeof(dui));
	q->n=0;
	q->head=0;
	q->lenght=lenght;
	q->data=(int *)malloc(sizeof(int)*lenght);
	return q;
}
void ru(dui *q,int val){
	q->data[q->wei]=val;
	if(q->wei+1==q->lenght) q->wei=0;
	else q->wei++;
	q->n++;
}
int chu(dui *q){
	if(q->n>0){
		int z=q->data[q->head];
		if(q->head+1==q->lenght) q->head=0;
		else q->head++;
		q->n--;
		return z;
	}
	return NULL;
}

int **eft(int lenght){
	int **q=(int **)malloc(sizeof(int *)*2);
	q[0]=(int *)malloc(sizeof(int)*(lenght+1));
	q[1]=(int *)malloc(sizeof(int)*(lenght+1));
	q[0][0]=0,q[1][0]=0;
	return q;
}
void addeft(int **q,int d,int val){
	int i=d&0x1;
	q[i][0]++;
	q[i][q[i][0]]=val;
}

V **initlb(int lenght){
	V **q=(V**)malloc(sizeof(V*)*(lenght+1));
	memset(q,0,sizeof(V*)*(lenght+1));
	return q;
}
int **initjz(int lenght){
	int **q=(int **)malloc(sizeof(int *)*(lenght+1));
	for(int i=0;i<=lenght;++i){
		q[i]=(int *)malloc(sizeof(int )*(lenght+1));
		memset(q[i],0,sizeof(int)*(lenght+1));
	}
	return q;
}
void addlb(V **q,int a,int b){
	V *v=(V *)malloc(sizeof(V));
	v->next=q[a];
	v->val=b;
	q[a]=v;
}
void addjz(int **q,int a,int b){
	q[a][b]=1;
	q[b][a]=1; 
}
bool eftlb(V **q,int **eft){//链表求二分图 ,时间复杂度为 V+E 
	dui *dd=cj(lenght);
	jd *a=(jd*)malloc(sizeof(jd)*(lenght+1));
	memset(a,0,sizeof(jd)*(lenght+1));
	a[1].b=true;
	a[1].d=0;
	ru(dd,1);
	while(dd->n){
		int val=chu(dd);
		V *v=q[val];
		addeft(eft,a[val].d,val);
		while(v){
			if(!a[v->val].b){
				a[v->val].b=true;
				a[v->val].d=a[val].d+1;
				a[v->val].p=val;
				ru(dd,v->val);
			}else if((a[v->val].d&0x1)==(a[val].d&0x1)) return false;
			v=v->next;
		}
	}
	return true;
}
bool eftjz(int **q,int **eft){//矩阵求二分图，时间复杂度为 V*V 
	dui *dd=cj(lenght);
	jd *a=(jd*)malloc(sizeof(jd)*(lenght+1));
	memset(a,0,sizeof(jd)*(lenght+1));
	a[1].b=1;
	a[1].d=0;
	ru(dd,1);
	while(dd->n){
		int  val=chu(dd);
		addeft(eft,a[val].d,val);
		for(int i=1;i<=lenght;++i){
			if(q[val][i]){
				if(!a[i].b){
					a[i].b=true;
					a[i].d=a[val].d+1;
					a[i].p=val;
					ru(dd,i);
				}else if((a[i].d&0x1)==(a[val].d&0x1)) return false;
			}
		}
	} 
	return true;
}
void *init(int n){
	void *q;
	if(n==1) q=initlb(lenght);
	else q=initjz(lenght);
	return q;
}
void add(void *q,int a,int b,int n){
	if(n==1) addlb((V **)q,a,b);
	else addjz((int **)q,a,b);
}
void bl(void *q,int n){
	int **qqq=eft(lenght);
	if(n==1){
		if(!eftlb((V **)q,qqq)){
			printf("chuduo\n");
			return ;
		}
	}else{
		if(!eftjz((int **)q,qqq)){
			printf("chuduo\n");
			return ;
		}
	}
	for(int i=1;i<=qqq[0][0];++i){
		printf("%d ",qqq[0][i]);
	}
	printf("    ");
	for(int i=1;i<=qqq[1][0];++i){
		printf("%d ",qqq[1][i]);
	}
	printf("\n");
}
int main(){
	while(1){
		printf("输入结点大小，1：链表。2：矩阵。\n");
		int c;
		scanf("%d%d",&lenght,&c);
		void *q=init(c);
		printf("输入边数 边\n");
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			add(q,u,v,c);
		}
		bl(q,c);
	}
}


