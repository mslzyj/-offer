#include <stdio.h>
#include <string.h>

void ShellInsert(int r[], int length,int dk)
{
	int j;
	for (int i = dk + 1; i < length; i++)
	{
		if (r[i] < r[i - dk])
		{
			r[0] = r[i];
			for (j = i - dk; j>0 && (r[0] < r[j]); j -= dk)
				r[j + dk] = r[j];
			r[j + dk] = r[0];
		}
	}
}
void SellSort(int arr[],int dlta[],int t,int length)
{
	for (int k = 0; k < length; t++)
		ShellInsert(arr, length, dlta[k]);
}
int main()
{
	int a[9] = { 0, 46, 25, 68, 33, 33, 19, 12,80 };
	int b[4] = {0};
	SellSort(a,b,4,9);
	for (int i = 1; i < 9; i++)
		printf("%3d", a[i]);
	printf("\n");
	return 0;
}