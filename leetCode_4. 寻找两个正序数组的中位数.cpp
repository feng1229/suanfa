#include<iostream>
using namespace std;

int main() {
	int a[]= {3};
	int b[]= {-2,-1};
	int l1=sizeof(a)/sizeof(a[0]);
	int l2=sizeof(b)/sizeof(b[0]);
	int l=(l1+l2)/2;
	double jg1,jg2;
	int a1=0,b1=0,ai,bi;
	while(1) {
		if(a1==l1) {
			if(b1+l>0)
				jg1=b[b1+l-1];
			jg2=b[b1+l];
			break;
		}
		if(b1==l2) {
			if(a1+l>0)
				jg1=a[a1+l-1];
			jg2=a[a1+l];
			break;
		}
		if(l==1) {
			if(a[a1]>b[b1]) {
				jg1=b[b1];
				if(b1+1!=l2&&b[b1+1]<a[a1])
					jg2=b[b1+1];
				else
					jg2=a[a1];
			} else {
				if(a1+1!=l1&&a[a1+1]<b[b1])
					jg2=a[a1+1];
				else
					jg2=b[b1];
				jg1=a[a1];
			}
			break;
		}
		if(l1-a1>l/2)
			ai=a1+l/2-1;
		else
			ai=l1-1;
		if(l2-b1>l/2)
			bi=b1+l/2-1;
		else
			bi=l2-1;
		if(a[ai]>b[bi]) {
			l=l-(bi-b1)-1;
			b1=bi+1;
		} else {
			l=l-(ai-a1)-1;
			a1=ai+1;
		}
		cout<<l<<"  ";
	}
	if((l1+l2)%2==0)
		jg2=(jg1+jg2)/2;
	cout<<jg2;
}

