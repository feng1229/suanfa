#include<stdio.h>
#include<stdlib.h>
#define Zhizhen long long
typedef struct LB {
	int key;
	Zhizhen np;
} lb;
lb *head;
lb *nil;
void INSERT(lb* );
int DELETE(int );
int SEARCH(int );
void nz();
int main() {
	head=(lb*)malloc(sizeof(lb));
	nil=(lb*)malloc(sizeof(lb));
	head->key=0;
	nil->key=0;
	nil->np=(Zhizhen)head^(Zhizhen)head;
	head->np=(Zhizhen)nil^(Zhizhen)nil;;

	//
	int k;
	int i;
	int a;
	lb *b;
	while(1) {
		printf("Ìí¼Ó £»1 É¾³ý£º2 ²éÑ¯£º3 Á´±íÄæ×ª£º 4\n");
		scanf("%d",&i);
		switch(i) {
			case 1:
				scanf("%d",&k);
				b=(lb*)malloc(sizeof(lb));
				b->key=k;
				INSERT(b);
				break;
			case 2:
				scanf("%d",&k);
				a=DELETE(k);
				if(a==0)printf("É¾³ýÊ§°Ü\n");
				break;
			case 3:
				scanf("%d",&k);
				a=SEARCH(k);
				if(a==0)printf("Ã»ÓÐ\n");
				break;
			case 4:
				nz();
				break;
		}
		lb *s=nil;
		lb *n=(lb*)((long long)head^nil->np);
		lb *l;
		while(n->key!=0) {
			printf("%d ",n->key);
			l=n;
			n=(lb *)((long long)s^n->np);
			s=l;
		}
		printf("\n");
	}
}

void INSERT(lb *a) {
	lb *w;
	w=(lb*)(head->np^(Zhizhen)nil);
	w->np=w->np^(Zhizhen)head^(Zhizhen)a;
	a->np=(Zhizhen)w^(Zhizhen)head;
	head->np=(Zhizhen)nil^(Zhizhen)a;
}
int DELETE(int key) {
	lb *s=nil,*n=(lb*)(s->np^(Zhizhen)head),*l;
	lb *next;
	while(n->key!=key) {
		l=n;
		n=(lb*)(n->np^(Zhizhen)s);
		s=l;
		if(n->key==0)return 0;
	}
	next=(lb*)((Zhizhen)s^n->np);
	s->np=s->np^(Zhizhen)next^(Zhizhen)n;
	next->np=(Zhizhen)n^next->np^(Zhizhen)s;
	return key;
}

int SEARCH(int key) {
	lb *s=nil,*n=(lb*)(s->np^(Zhizhen)head),*l;
	while(n->key!=key) {
		l=n;
		n=(lb*)(n->np^(Zhizhen)s);
		s=l;
		if(n->key==0)return 0;
	}
	return n->key;
}

void nz() { //Ë«Á´±íÄæ×ª
	lb *wei=(lb*)((Zhizhen)nil^head->np);
	lb *one=(lb*)((Zhizhen)head^nil->np);
	head->np=(Zhizhen)nil^(Zhizhen)one;
	nil->np=(Zhizhen)head^(Zhizhen)wei;
	one->np=one->np^(Zhizhen)nil^(Zhizhen)head;
	wei->np=wei->np^(Zhizhen)nil^(Zhizhen)head;
}
