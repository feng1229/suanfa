/*≤Â»Î≈≈–Ú 
*/
#include<iostream>
using namespace std;

int main()
{
	int a[]={5,6,7,11,25,45,14,2,65,9,44};
	int a_length=sizeof(a)/sizeof(a[0]);
	int key=0;
	int j=0;
	int ci=0;
	for(int i=1;i<a_length;i++)
	{
	
		key=a[i];
		j=i-1;
		while((key>a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j--;
			ci++;
		}
		a[j+1]=key;
	}
	for(int i=0;i<a_length;i++)cout<<a[i]<<endl;
	cout<<ci<<"¥Œ";
	
	return 0;
}
