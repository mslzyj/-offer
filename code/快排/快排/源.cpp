#include <stdio.h>
int QKpass(int r[],int low,int high)
{
	r[0] = r[low];
	while (low < high)
	{
		while (low<high && r[high]>=r[0])
			--high;
		r[low] = r[high];
		while (low < high && r[low] < r[0]) 
			++low;
		r[high] = r[low];
	}
	r[low] = r[0];
	return low;
}
void QKSort(int r[],int low,int high)
{
	int pos;
	if (low < high)
	{
		pos = QKpass(r,low,high);
		QKSort(r,low,pos-1);
		QKSort(r,pos+1,high);
	}
}
int main()
{
	int a[9] = { 0, 46, 68, 12, 25, 33, 80, 19, 33 };
	QKSort(a,1,8);
	for (int i = 1; i < 9; i++)
		printf("%3d",a[i]);
	printf("\n");
}