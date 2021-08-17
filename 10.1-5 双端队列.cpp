//在队列里实现双端入队出队
#include<stdio.h>
#include<stdlib.h>

int *a;
int head=0,tail=0,n=0,N;
int head_ENQUEUE(int);
int head_DEQUEUE();
int tail_ENQUEUE(int);
int tail_DEQUEUE();
int main() {
	printf("输入队列长度\n");
	scanf("%d",&N);
	a=(int *)malloc(sizeof(int)*N);
	for(int i=0; i<N; i++)a[i]=0;
	printf("操作 数据：1 头入队，2 头出队，3 尾入队，4 尾出队\n");
	int sc,sj;
	int n;
	while(1) {
		scanf("%d",&sc);
		switch(sc) {
			case 1:
				scanf("%d",&sj);
				head_ENQUEUE(sj);
				break;
			case 2:
				n=head_DEQUEUE();
				if(n)printf("%d ",n);
				break;
			case 3:
				scanf("%d",&sj);
				tail_ENQUEUE(sj);
				break;
			case 4:
				n=tail_DEQUEUE();
				if(n)printf("%d ",n);
				break;
		}
		printf("数组：");
		for(int i=0; i<N; i++)printf("%d ",a[i]);
		printf("\n");
	}
}

int head_ENQUEUE(int key) {//入队
	if(n>=N) {
		printf("上溢\n");
		return 0;
	}
	if(head==0)
		head=N-1;
	else
		head--;
	a[head]=key;
	n++;
	return 1;
}

int head_DEQUEUE() {
	if(n<=0) {
		printf("下溢\n");
		return 0;//下溢
	}
	int key=a[head];
	if(head==N-1)
		head=0;
	else
		head++;
	n--;
	return key;
}

int tail_ENQUEUE(int key) {
	if(n>=N) {
		printf("上溢\n");
		return 0;
	}
	a[tail]=key;
	if(tail==N-1)
		tail=0;
	else
		tail++;
	n++;
	return 1;
}

int tail_DEQUEUE() {
	if(n<=0) {
		printf("下溢\n");
		return 0;
	}
	if(tail==0)
		tail=N-1;
	else
		tail--;
	n--;
	return a[tail];
}
