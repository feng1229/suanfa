/*¿ìËÙÅÅĞò 
*/ 
#include<iostream>
using namespace std;

void paiqu(int* ,int);
int main(){
	int a[]={54454,5455,454,456,544,4,213,521,64,633,52,35,524,24,4,654,6};
	int a_length=sizeof(a)/sizeof(a[0]);
	paiqu(a,a_length); 
	for(int i=0;i<a_length;i++)cout<<a[i]<<endl;
} 

void paiqu(int a[],int n){
	int left=0,right=0;
	int x=a[n-1];
	int next=0;
	for(int i=0;i<n-1;i++){
		if(a[i]<x){
			next=a[left];
			a[left]=a[i];
			a[i]=next;
			left++;
		}
	}
	next=a[left];
	a[left]=x;
	a[n-1]=next;
	right=n-left-1;
	if(left>2)paiqu(a,left);
	if(right>2)paiqu(&a[left+1],right);
}
