/*堆排序 最大堆 
*/
#include<iostream> 
#define LEFT(x) (2*(i))
#define RIGHT(x) (2*(i)+1)
using namespace std;

void paixu(int* ,int);
void gengxin(int* ,int,int);
int main(){
	int a[]={54,51,5451,215,613,21,21,5,5131,5,21,221,2,31};
	int a_length=sizeof(a)/sizeof(a[0]);
	paixu(a,a_length);
	
	for(int i=0;i<a_length;i++)cout<<a[i]<<endl; 
}
void paixu(int a[],int n){
	int next=0;
	for(int i=n/2;i>0;i--)gengxin(a,i,n);
	for(int i=n-1;i>0;i--){
		next=a[i];
		a[i]=a[0];
		a[0]=next;
		gengxin(a,1,i);
	}
}
void gengxin(int a[],int i,int n){//i为第几个数，第一个为i[0]; 
	int big=i;
	if((LEFT(i)<=n)&&(a[LEFT(i)-1]>a[i-1]))big=LEFT(i);
	if((RIGHT(i)<=n)&&(a[RIGHT(i)-1]>a[big-1]))big=RIGHT(i);
	if(big==i) return;
	int next=a[i-1];
	a[i-1]=a[big-1];
	a[big-1]=next;
	gengxin(a,big,n);
}
