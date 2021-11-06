#include<stdlib.h>
#include<stdio.h>
#define MAX 100
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)+1)
#define P(x) (x>>1)
#define swap(x,y) \
struct qwe *ww=*x;\
*x=*y;\
*y=ww;
int duilen=0;
int zhanlen=0;
struct qwe{
	int val;
	int k;
};
void add(struct qwe **a,struct qwe *b,int *len){
	int p=*len; 
	while(a[P(p)]->k>b->k){
		a[p]=a[P(p)];
		p=P(p);
	}
	a[p]=b;
} 
void weihu(struct qwe **a,int i,int len){
	int min=i;
	do{
		int l=LEFT(min);
		int r=RIGHT(min);
		i=min;
		if(l<=len&&a[l]->k<a[min]->k) min=l;
		if(r<=len&&a[r]->k<a[min]->k) min=r;
		if(i!=min){
			swap(&a[i],&a[min]);
		}
	}while(i!=min);
}
int mindet(struct qwe **a,int len){
	int q=a[1]->val;
	free(a[1]);
	a[1]=a[len];
	weihu(a,1,len-1);
	return q;
}
void adddl(struct qwe **a,int key,int *len){
	struct qwe *q=(struct qwe *)malloc(sizeof(struct qwe));
	*len+=1;
	q->k=*len;
	q->val=key;
	add(a,q,len);
}
void addzhan(struct qwe **a,int key,int *len){
	struct qwe *q=(struct qwe *)malloc(sizeof(struct qwe));
	*len+=1;
	q->k=0xFFFFFF-*len;
	q->val=key;
	add(a,q,len);
}
int chu(struct qwe **a,int *len){
	*len-=1;
	return(mindet(a,*len+1));
}
int main(){
	struct qwe **dui=(struct qwe **)malloc(sizeof(struct qwe *)*MAX);
	struct qwe **stack=(struct qwe **)malloc(sizeof(struct qwe *)*MAX);
	struct qwe *q=(struct qwe *)malloc(sizeof(struct qwe));
	q->k=0;
	dui[0]=q;
	q=(struct qwe *)malloc(sizeof(struct qwe));
	q->k=0;
	stack[0]=q;
	printf("1：入队列，2：入栈。3：出队列。4：出栈。\n");
	int n,c;
	do{
		scanf("%d",&c);
		switch(c){
			case 1:
				scanf("%d",&n);
				for(int i=0;i<n;++i){
					scanf("%d",&c);
					adddl(dui,c,&duilen); 
				}
				break;
			case 2:
				scanf("%d",&n);
				for(int i=0;i<n;++i){
					scanf("%d",&c);
					addzhan(stack,c,&zhanlen); 
				}
				break;
			case 3:
				 while(duilen>0)printf("%d ",chu(dui,&duilen));
				 printf("\n");
				 break;
			case 4:
				 while(zhanlen>0)printf("%d ",chu(stack,&zhanlen));
				 printf("\n");
				 break;
		}
	}while(1);
}
