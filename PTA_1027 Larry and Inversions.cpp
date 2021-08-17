#include<stdio.h>
#include<stdlib.h>
int **T;
int **TT;
int num=0;
struct Shu {
	int key;
	int idex;
};
int *fen_i_d;
int *fen_i_x;
int *fuben_b_i_d;
int *fuben_b_i_x;
struct Shu **fuben_b;
struct Shu **fuben;
struct Shu **shuru;

void guipin(struct Shu **,int ,int);
void guipinpaixu(struct Shu**,int ,int ,int );

int main() {
	int N;
	int number;
	struct Shu *s;
	scanf("%d",&N);

	//malloc
	T=(int **)malloc(sizeof(int *)*N);
	TT=(int **)malloc(sizeof(int *)*N);
	struct Shu **a=(struct  Shu**)malloc(sizeof(struct Shu*)*N);
	fuben=(struct Shu**)malloc(sizeof(struct Shu*)*(N/2+1));
	fuben_b=(struct Shu**)malloc(sizeof(struct Shu*)*(N/2+1));
	shuru=(struct Shu**)malloc(sizeof(struct Shu*)*N);
	fen_i_d=(int *)malloc(sizeof(int)*(N/2+1));
	fen_i_x=(int *)malloc(sizeof(int)*(N/2+1));
	fuben_b_i_d=(int *)malloc(sizeof(int)*(N/2+1));
	fuben_b_i_x=(int *)malloc(sizeof(int)*(N/2+1));
	for(int i=0; i<N; i++) {
		T[i]=(int*)malloc(sizeof(int)*N);
		TT[i]=(int*)malloc(sizeof(int)*N);
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			T[i][j]=0;
	for(int i=0; i<N; i++) {
		s=(struct Shu*)malloc(sizeof(struct Shu));
		scanf("%d",&(s->key));
		s->idex=i;
		shuru[i]=s;
		a[i]=s;
	}
	guipin(a,0,N-1);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			TT[i][j]=num;
	for(int i=0; i<N-1; i++) {
		int q=i-1,h=i+1;
		while(q>=0&&h<N) {
			if(shuru[q]->key>shuru[h]->key)
				TT[q][h]=TT[q+1][h-1]-2*T[q][h]-1;
			else
				TT[q][h]=TT[q+1][h-1]+2*T[q][h]+1;
			q--;
			h++;
		}
		if(shuru[i]->key>shuru[i+1]->key)
			TT[i][i+1]=num-1;
		else
			TT[i][i+1]=num+1;
		q=i-1;
		h=i+2;
		while(q>=0&&h<N) {
			if(shuru[q]->key>shuru[h]->key)
				TT[q][h]=TT[q+1][h-1]-2*T[q][h]-1;
			else
				TT[q][h]=TT[q+1][h-1]+2*T[q][h]+1;
			q--;
			h++;
		}
	}
	printf("%d",num);
	for(int i=0; i<N-1; i++) {
		for(int j=i+1; j<N; j++) 
			printf(" %d",TT[i][j]);
		printf(" %d",num);
	}
}
void guipin(struct Shu **a,int l,int r) {
	if(l<r) {
		int z=(l+r)/2;
		guipin(a,l,z);
		guipin(a,z+1,r);
		guipinpaixu(a,l,z,r);
	}
}
void guipinpaixu(struct Shu **a,int l,int z,int r) {//Ð¡µ½´ó
	for(int i=0; i<=(z-l); i++)
		fuben[i]=a[l+i];
	for(int j=0; j<(r-z); j++)
		fuben_b[j]=a[z+j+1];
	int i=0,f_i=0,a_i=0;
	while(i<=(r-l)) {
		if(a_i>=(r-z)||f_i<=(z-l)&&fuben[f_i]->key<fuben_b[a_i]->key )  {
			fen_i_d[f_i]=a_i;
			fen_i_x[f_i]=a_i-1;
			a[l+i]=fuben[f_i];
			num+=(i-f_i);
			f_i++;
		} else {
			a[l+i]=fuben_b[a_i];
			fuben_b_i_x[a_i]=f_i-1;
			fuben_b_i_d[a_i]=f_i;
			a_i++;
		}
		i++;
	}

	for(int i=0; i<=(z-l); i++) {
		for(int j=0; j<(r-z); j++) {
			if(fuben[i]->key<fuben_b[j]->key) {
				int zuo=fuben_b_i_x[j];
				int you=fen_i_d[i];
				int i_i=fuben[i]->idex;
				int j_i=fuben_b[j]->idex;
				int zuo_i=fuben[zuo]->idex;
				int you_i=fuben_b[you]->idex;
				int d=zuo_i;
				int x=i_i;

				if(zuo_i<i_i) {
					d=i_i;
					x=zuo_i;
				}
				if(fuben_b[you]->idex<fuben_b[j]->idex) {
					T[i_i][j_i]=zuo-i-T[d][x]+T[j_i][you_i]+T[you_i][j_i]+1;
					if(you==j)T[i_i][j_i]--;
				} else {
					T[i_i][j_i]=zuo-i-T[d][x]+T[you_i][j_i]-T[j_i][you_i]-1;
					if(you==j)T[i_i][j_i]++;
				}
				T[j_i][i_i]=T[d][x];
			} else {
				int zuo=fuben_b_i_d[j];
				int you=fen_i_x[i];
				int i_i=fuben[i]->idex;
				int j_i=fuben_b[j]->idex;
				int zuo_i=fuben[zuo]->idex;
				int you_i=fuben_b[you]->idex;
				int d=j_i;
				int x=you_i;
				if(j_i<you_i) {
					d=you_i;
					x=j_i;
				}

				if(fuben[zuo]->idex<fuben[i]->idex) {
					T[i_i][j_i]=i-zuo-T[zuo_i][i_i]-T[i_i][zuo_i]+T[d][x]-1;
					if(zuo==i)T[i_i][j_i]++;
				} else {
					T[i_i][j_i]=i-zuo-T[zuo_i][i_i]+T[i_i][zuo_i]+T[d][x]+1;
					if(zuo==i)T[i_i][j_i]--;
				}
				T[j_i][i_i]=T[d][x]+i-zuo+1;
			}
		}
	}
	for(int i=0; i<r-z-1; i++) {
		int i_i=fuben_b[i]->idex;
		for(int j=i+1; j<r-z; j++) {
			int j_i=fuben_b[j]->idex;
			if(i_i>j_i) {
				if(fuben_b_i_d[j]!=fuben_b_i_d[i])
					T[i_i][j_i]+=(fuben_b_i_x[j]-fuben_b_i_d[i]+1);
			} else {
				if(fuben_b_i_d[j]!=fuben_b_i_d[i])
					T[j_i][i_i]+=(fuben_b_i_x[j]-fuben_b_i_d[i]+1);
			}
		}
	}
}
