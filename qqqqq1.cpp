#include <stdio.h>
#include<sys/timeb.h>
int dp[1000][6000];
struct node{
    int weight;
    int price;
};
long int nnn=0; 
long int nn=0;
int max(int a, int b){//nn++;
    return a > b ? a : b;
}

int dp1(struct node *goods, int size, int weight){
    for(int i = 0; i < size; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= weight; i++){
        if(i < goods[0].weight){
            dp[0][i] = 0;
        }
        else{
            dp[0][i] = goods[0].price;
        }
    }

    for(int j = 1; j <= weight; j++){
        for(int i = 1; i < size; i++){
            if(j < goods[i].weight){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - goods[i].weight] + goods[i].price);
            }
        }
    }
    return dp[size - 1][weight];
}


int dp2_fixup(struct node *goods, int size, int weight){nnn++;
    if(dp[size][weight] != -1){
        return dp[size][weight];
    }
    if(weight == 0){
        dp[size][weight] = 0;
        return dp[size][weight];
    }
    if(weight < goods[size].weight){
        if(size == 0){
            dp[size][weight] = 0;
        }
        else{
            dp[size][weight] = dp2_fixup(goods, size - 1, weight);
        }
    }
    else{
        if(size == 0){
            dp[size][weight] = goods[size].price;
        }
        else{ nn++;
            dp[size][weight] = max(dp2_fixup(goods, size - 1, weight), dp2_fixup(goods, size - 1, weight - goods[size].weight) + goods[size].price);
        }
    } 
    return dp[size][weight];
}

int dp2(struct node *goods, int size, int weight){
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= weight; j++){
            dp[i][j] = -1;
        }
    }
    return dp2_fixup(goods, size - 1, weight);
}

int p(int i){
	nnn++;
	if(i<2)return 1;
	int a=p(i-1);
	int b=p(i-2);
	return a+b;
}
int main()
{
//	struct timeb t1,t2;
//	int u;
//	scanf("%d",&u);
//	ftime(&t1);
//	int uu=p(u);
//	ftime(&t2);
//	printf("%d %d",uu,u);
//	printf(" %d",nnn);
//	long t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
//	printf(" %ld",t);
//	return 0;
    struct node goods[1000];
    int n = 1000;
    int weight = 600;
    for(int i = 0; i < n; i++){
        scanf("%d", &goods[i].weight);
        scanf("%d", &goods[i].price);
    }
    struct timeb t1,t2;
    ftime(&t1);
    printf("%d\n", dp1(goods, n, weight));
    /* printf("%d\n", dp1(goods, n, weight)); */
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j <= weight; j++){
//            printf("%d ", dp[i][j]);
//        }
ftime(&t2);
long t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
        printf("\n %d %d ",nnn,nn);
        printf(" %ld",t);
//    }

    return 0;
}
