
#include<stdio.h>
#include<malloc.h>
#define MAX1 100
#define MAX 0x80000001
//#define NULL 0
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)+1)
#define P(x) (x>>1)
#define swap(x,y) \
int qqq=*x;\
*x=*y;\
*y=qqq;
 int lenght=0;
 void weihu(int *a,int i){
 	int min=i;
 	do{
 		i=min;
 		int l=LEFT(i);
 		int r=RIGHT(i);
 		if(l<=lenght&&a[l]<a[min])min=l;
 		if(r<=lenght&&a[r]<a[min])min=r;
 		if(min!=i){
 			swap(&a[i],&a[min]);
		 }
	 }while(i!=min); 
 }
int retmin(int *a){
	if(lenght<1)return -1;
	return a[1];
}
int retMinDet(int *a){
	if(lenght<1)return -1;
	int q=a[1];
	a[1]=a[lenght--];
	weihu(a,1);
	return q;
}
void det(int *a){
	if(lenght<1)return ;
	a[1]=a[lenght--];
	weihu(a,1);
}
void add(int *a,int b){
	int p=++lenght;
	while(a[P(p)]>b){
		a[p]=a[P(p)];
		p=P(p);
	}
	a[p]=b;
}
int main(){
	int *a=(int *)malloc(sizeof(int)*MAX1);
	a[0]=MAX;
	int c;
	printf("1：加入，2：最小，3：最小并删除，4：删除最小。\n"); 
	do{
		scanf("%d",&c);
		int n;
		switch(c){
			case 1:
				scanf("%d",&n);
				for(int i=0;i<n;++i){
					scanf("%d",&c);
					add(a,c);
				}
				break;
			case 2:
				printf("%d ",retmin(a));
				break;
			case 3:
				printf("%d ",retMinDet(a));
				break;
			case 4:
				det(a);
				break;
		}
	}while(1);
} 
