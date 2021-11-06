#include<stdio.h>

int main(){
	int a[10]={31,945,615,7464,7853,654,34,9874,612,98465};
	int lenght=10;
	for(int i=1;i<lenght;++i){
		int j=i-1;
		int val=a[i];
		while(j>=0&&val>a[j]){
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=val;
	}
	for(int i=0;i<lenght;++i)printf("%d ",a[i]);
} 
