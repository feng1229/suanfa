#include<stdio.h>
#include<stdlib.h>
struct suxia {
	int key;
	int x;
};
struct suxia **fuben;
void guipin(struct suxia**,int ,int);
void guipingpaixu(struct suxia**,int,int ,int);
int main() {
	int N;
	scanf("%d",&N);
	fuben=(	struct suxia **)malloc(sizeof(	struct suxia *)*(N/2+1) );
	struct suxia **shu=(struct suxia **)malloc(sizeof(struct suxia*)*N );
	struct suxia **jieguo=(struct suxia **)malloc(sizeof(struct suxia)*N );
	for(int i=0; i<N; i++) {
		struct suxia* s=(struct suxia*)malloc(sizeof(struct suxia));
		scanf("%d",&(s->key));
		s->x=0;
		shu[i]=s;
		jieguo[i]=s;
	}
	guipin(shu,0,N-1); 
	printf("%d",jieguo[0]->x);
	for(int i=1; i<N; i++)
		printf(" %d",jieguo[i]->x);
}

void guipin(struct suxia **a,int l,int r) {
	if(l<r) {
		int z=(l+r)/2;
		guipin(a,l,z);
		guipin(a,z+1,r);
		guipingpaixu(a,l,z,r);
	}
}
void guipingpaixu(struct suxia **a,int q,int z,int h) {
	for(int i=0; i<=(z-q); i++) {
		fuben[i]=a[q+i];
	}
	int i=0,j=1,k=0;
	while(i<=(h-q)) {
//		if(j>(h-z)){
//			a[q+i]=fuben[k];
//			a[q+i]->x+=(i-k);
//			k++;
//			i++;
//			continue;
//		}
		if(j>(h-z)||k<=z-q&&fuben[k]->key<a[z+j]->key) {
			a[q+i]=fuben[k];
			a[q+i]->x+=(i-k);
			k++;
		} else {
			a[q+i]=a[z+j];
			j++;
		}
		i++;
	}
}
