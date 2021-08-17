#include<iostream>
#include<malloc.h>
#define _int int
using namespace std;
// 1 1 2 2 3 4 4 8 5 10 6 20 7 40 8 80 9 100 10 200ox
short **f_xia;
short **h_xia;
short **l_xia;
_int **fz;
short *stack1,*stack2,top=-1,num=0;
short *fankuai;
short *hang;
short *lie;
_int *dui;
short lenght=0;
short weihu(short ,short );
_int qushu();
short wei(short );
void dui_weihu(_int ,short );
short add(char a[][9],short,short ,short  );
void wap(short ,short );
void solveSudoku(char board[][9], int boardSize, int* boardColSize) {
	fankuai=(short *)malloc(sizeof(short)*boardSize);
	hang=(short *)malloc(sizeof(short)*boardSize);
	lie=(short *)malloc(sizeof(short)*boardSize);
	short su[10]= {0x0,0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100};
	f_xia=(short **)malloc(sizeof(short*)*boardSize);
	h_xia=(short **)malloc(sizeof(short*)*boardSize);
	l_xia=(short **)malloc(sizeof(short*)*boardSize);
	fz=(_int **)malloc(sizeof(_int*)*boardSize);
	for(int i=0; i<boardSize; i++) {
		f_xia[i]=(short *)malloc(sizeof(short)*10);
		h_xia[i]=(short *)malloc(sizeof(short)*10);
		l_xia[i]=(short *)malloc(sizeof(short)*10);
		fz[i]=(_int *)malloc(sizeof(_int)*boardSize);
		f_xia[i][0]=0,h_xia[i][0]=0,l_xia[i][0]=0;
		fankuai[i]=0;
		hang[i]=0;
		lie[i]=0;
	}
	short k,t,min=9;
	for(short i=0; i<boardSize; i++)
		for(short j=0; j<boardSize; j++) {
			if(board[i][j]!='.') {
				k=su[board[i][j]-'0'];
				hang[i]|=k;
				lie[j]|=k;
				fankuai[i/3*3+j/3]|=k;
			} else {
				h_xia[i][++h_xia[i][0]]=i<<4|j;
				l_xia[j][++l_xia[j][0]]=i<<4|j;
				f_xia[i/3*3+j/3][++f_xia[i/3*3+j/3][0]]=i<<4|j;
				fz[i][j]=i<<4|j;
				++num;
			}
		}
	dui=(_int *)malloc(sizeof(_int)*(num+1));
	stack1=	(short *)malloc(sizeof(short)*num);//ij
	stack2=	(short *)malloc(sizeof(short)*num);//t
	short i,j,tf,b;
	_int p;
	for(short q=0; q<boardSize; q++)
		for(short o=1; o<=h_xia[q][0]; o++) {
			i=q,j=h_xia[q][o]&0xF;
			t=(fankuai[i/3*3+j/3]|hang[i]|lie[j])^0x1FF;
			fz[i][j]|=wei(t)<<8;
			dui_weihu(fz[i][j],1);
		}
	while(num) {
		p=qushu();
		i=p>>4&0xF,j=p&0xF;
		t=(fankuai[i/3*3+j/3]|hang[i]|lie[j])^0x1FF;
		b= add(board,t,i,j);
		if(!b)do {
				++num;
				i=stack1[top]>>4;
				j=stack1[top]&0xF;
				tf=stack2[top];
				--top;
				hang[i]&=~tf;
				lie[j]&=~tf;
				fankuai[i/3*3+j/3]&=~tf;
				t=(fankuai[i/3*3+j/3]|hang[i]|lie[j])^0x1FF;
				while((t&(-t))<tf)
					t-=t&(-t);
				t-=tf;
				weihu(i,j);
				if(t) {
					if(add(board,t,i,j))break;
					else
						continue;
				}
				t=(fankuai[i/3*3+j/3]|hang[i]|lie[j])^0x1FF;
				h_xia[i][++h_xia[i][0]]=i<<4|j;
				l_xia[j][++l_xia[j][0]]=i<<4|j;
				f_xia[i/3*3+j/3][++f_xia[i/3*3+j/3][0]]=i<<4|j;
				fz[i][j]=fz[i][j]&0xFFFF00FF|(wei(t)<<8);
				dui_weihu(fz[i][j],1);
			} while(1);
	}
}
short add(char board[][9],short t,short i,short j) {
	--num;
	stack1[++top]=i<<4|j;
	t&=(-t);
	stack2[top]=t;
	hang[i]|=t;
	lie[j]|=t;
	fankuai[i/3*3+j/3]|=t;
	if(!weihu(i,j)) return 0;
	short k=0;
	while(t) {
		t>>=1;
		++k;
	}
	board[i][j]='0'+k;
	return 1;
}
short weihu(short i,short j) {
	short ii,jj,k,t,b=1;
	for(int e=1; e<=h_xia[i][0]; e++) {
		jj=h_xia[i][e]&0xF;
		if(jj==j) {
			h_xia[i][e]=h_xia[i][h_xia[i][0]];
			--h_xia[i][0];
			--e;
			continue;
		}
		if(!b)continue;
		t=(fankuai[i/3*3+jj/3]|hang[i]|lie[jj])^0x1FF;
		k=wei(t);
		if(!k) {
			b=0;
			continue;
		}
		fz[i][jj]=fz[i][jj]&0xFFFF00FF|k<<8;
		dui_weihu(fz[i][jj],0);
	}
	for(int e=1; e<=l_xia[j][0]; e++) {
		ii=l_xia[j][e]>>4;
		if(ii==i) {
			l_xia[j][e]=l_xia[j][l_xia[j][0]];
			--l_xia[j][0];
			--e;
			continue;
		}
		if(!b)continue;
		t=(fankuai[ii/3*3+j/3]|hang[ii]|lie[j])^0x1FF;
		k=wei(t);
		if(!k) {
			b=0;
			continue;
		}
		fz[ii][j]=fz[ii][j]&0xFFFF00FF|k<<8;
		dui_weihu(fz[ii][j],0);
	}
	for(int e=1; e<=f_xia[i/3*3+j/3][0]; e++) {
		jj=f_xia[i/3*3+j/3][e]&0xF;
		ii=f_xia[i/3*3+j/3][e]>>4;
		if(ii==i&&jj==j) {
			f_xia[i/3*3+j/3][e]=f_xia[i/3*3+j/3][f_xia[i/3*3+j/3][0]];
			--f_xia[i/3*3+j/3][0];
			--e;
			continue;
		}
		if(!b)continue;
		t=(fankuai[ii/3*3+jj/3]|hang[ii]|lie[jj])^0x1FF;
		k=wei(t);
		if(!k) {
			b=0;
			continue;
		}
		fz[ii][jj]=fz[ii][jj]&0xFFFF00FF|k<<8;
		dui_weihu(fz[ii][jj],0);
	}
	return b;
}
short wei(short t) {
	short k=0;
	while(t) {
		t-=t&(-t);
		++k;
	}
	return k;
}
void dui_weihu(_int a,short q) {
	short i,min;
	if(q) {
		dui[++lenght]=a;
		fz[a>>4&0xF][a&0xF]=fz[a>>4&0xF][a&0xF]&0xFFFF|lenght<<16;
		i=lenght;
	} else
		i=a>>16;
	while(i>1) {
		if((dui[i]>>8&0xFF)<=(dui[i/2]>>8&0xFF)) {
			wap(i,i/2);
			i=i/2;
		} else
			break;
	}
	if(!q&&i==a>>16 ) {
		while(2*i<=lenght) {
			if((dui[2*i]>>8&0xFF)<(dui[i]>>8&0xFF))
				min=2*i;
			else min=i;
			if(2*i<lenght&&(dui[2*i+1]>>8&0xFF)<(dui[min]>>8&0xFF))
				min=2*i+1;
			if(min!=i) {
				wap(i,min);
				i=min;
			} else
				break;
		}
	}
}
void wap(short la,short lb) {
	_int w=dui[la];
	dui[la]=dui[lb];
	dui[lb]=w;
	fz[dui[la]>>4&0xF][dui[la]&0xF]=fz[dui[la]>>4&0xF][dui[la]&0xF]&0xFFFF|la<<16;
	fz[dui[lb]>>4&0xF][dui[lb]&0xF]=fz[dui[lb]>>4&0xF][dui[lb]&0xF]&0xFFFF|lb<<16;
}
_int qushu() {
	_int a=dui[1];
	dui[1]=dui[lenght];
	--lenght;
	fz[dui[1]>>4&0xF][dui[1]&0xF]=fz[dui[1]>>4&0xF][dui[1]&0xF]&0xFFFF|1<<16;
	short i=1,min;
	while(2*i<=lenght) {
		if((dui[2*i]>>8&0xFF)<(dui[i]>>8&0xFF))
			min=2*i;
		else min=i;
		if(2*i<lenght&&(dui[2*i+1]>>8&0xFF)<(dui[min]>>8&0xFF))
			min=2*i+1;
		if(min!=i) {
			wap(i,min);
			i=min;
		} else
			break;
	}
	return a;
}

int main() {
	char board[][9] = {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
//	char board[][9] = [[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]
	int i=9;
	int	k=0;
	int	t=0xF00;
	t=t&0xF00|1<<4;
//while(t){
//			t-=t&(-t);
//			k++;
//	} ;
	cout<<t;
	solveSudoku(board, 9, &i);//for(int i=0;i<52;i++)cout<<(*dui[i]>>8&0xFF)<<" ";
//	cout<<lenght;
	cout<<endl;
	for(int i=0; i<9; i++) {

		for(int j=0; j<9; j++)

			cout<<board[i][j]<<" ";
		cout<<endl;
	}

}
