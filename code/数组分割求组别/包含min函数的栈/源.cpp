#include<stdio.h>
#define MAX 100

void counts(int n,int a[],int b[],int j,int q)
{
	int count = 0;
	for (int i = 0; i < n+1; i++)
	{
		if (count<(b[j])){
			count += a[i];
		}
		else
		{
			printf("%d\n", i);
			break;
		}
	}
}
int main()
{
	int n, a[MAX] = {0};
	int q, b[MAX] = {0};
	int count = 0;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	scanf_s("%d", &q);
	for (int j = 0; j < q; j++)
		scanf_s("%d", &b[j]);

	for (int j = 0; j < q; j++){
		counts(n, a, b, j, q);
	}
	return 0;
}

/*
5
2 7 3 4 9
3
1 25 11
1
5
3
请按任意键继续. . .

*/