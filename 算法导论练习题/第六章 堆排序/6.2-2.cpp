//最小堆  运行时间一样 
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)+1)
#define swap(x,y) /
int aa=x;/
x=y;/
y=aa;
int lenght;
void aaa(int *a,int i){
	int min=i;
	do{
		i=min;
		int l=LEFT(i);
		int r=RIGHT(i);
		if(l<=lenght&&a[l]<a[i]) min=l;
		if(r<=lenght&&a[r]<a[min]) min=r;
		if(i!=min){
			swap(a[i],a[min]);
		}
	}while(min!=i);
} 
