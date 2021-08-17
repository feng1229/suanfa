// 用一个数组实现2个栈，其元素之和不超数组个数是不会上溢
//纯C 
#include<stdio.h>
#include<stdlib.h>
struct Stack {
	int top;
	int i;
};
int n;
struct Stack *stack1,*stack2;
int *a;
void stack_jia(int *);
void PUSH(struct Stack *,int ) ;
int POP(struct Stack *);
int main() {
	int N=10;
	printf("输入数组个数\n");
	scanf("%d",&N);
	n=N-1;
	printf("输入：栈 操作 （数字）：栈有2个（1和2） 操作2个（1为压入，2为弹出）\n");

	stack1=(struct Stack* )malloc(sizeof(struct Stack));
	stack2=(struct Stack* )malloc(sizeof(struct Stack));
	a=(int *)malloc(sizeof(int)*N);
	for(int i=0; i<N; i++)a[i]=0;
	stack1->top=-2;
	stack1->i=0;
	stack2->top=-1;
	stack2->i=1;

	//测试
	int z,cc,sz;
	struct Stack *s;
	while(1) {
		scanf("%d %d",&z,&cc);
		switch(z) {
			case 1:
				s=stack1;
				break;
			case 2:
				s=stack2;
		}
		switch(cc) {
			case 1:
				scanf("%d",&sz);
				PUSH(s,sz);
				break;
			case 2:
				int n=POP(s);
				if(n!=-1)
					printf("弹出：%d \n",n);
		}
		printf("数组：");
		for(int i=0; i<N; i++)printf("%d ",a[i]);
		printf("\n");
	}



}

void stack_jia(int *a) {
	*a+=2;
	switch(*a-n) {
		case 1:
			*a-=1;
			break;
		case 2:
			*a-=3;
			break;
	}
}

void PUSH(struct Stack *s,int n) { //压入
	int top=s->top;
	if(s->top%2==s->i||s->top<0)
		stack_jia(&(s->top));
	else
		s->top-=2;
	if(s->top==stack1->top&&s->top==stack2->top) {
		printf("上溢 ");
		s->top=top;
	} else
		a[s->top]=n;
}
int POP(struct Stack *s) {
	if(s->top<0) {
		printf("下溢 ");
		return -1;
	}
	int n=a[s->top];
	if(s->top%2==s->i)
		s->top-=2;
	else
		stack_jia(&(s->top));
	return n;
}

