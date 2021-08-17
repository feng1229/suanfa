#include <iostream> 
using namespace std;

int main()
{
	int a[]={5,6,7,11,25,45,14,2,65,9,44 };
	int a_length=sizeof(a)/sizeof(a[0]);
	int key=0;
	int j=0;
	int ci=0;
	for(int i=0;i<a_length;i++)
	{
		for(j=i+1;j<a_length;j++)
		{
			key=a[i];
			if(a[i]<a[j])
			{
				a[i]=a[j];
				a[j]=key;
			}
			ci++;
		}
	}
	for(int i=0;i<a_length;i++)cout<<a[i]<<endl;
	cout<<ci;
	return 0;
}
