#include <stdio.h>
//ºÚµ•—°‘Ò≈≈–Ú
void SelectSort(int r[],int length)
{
	int k,t;
	for (int i = 1; i < length ; i++)
	{
		k = i;
		for (int j = i + 1; j < length;j++)
		  if (r[j] < r[k])
			 k = j;
		  if (k != i)
		  {
			  t = r[i];
			  r[i] = r[k];
			  r[k] = t;
		  }
	}
}
int main()
{
	int a[9] = { 0, 46, 68, 12, 25, 33, 80, 19, 33 };
	SelectSort(a,9);
	for (int i = 1; i < 9; i++)
		printf("%3d", a[i]);
	printf("\n");
}