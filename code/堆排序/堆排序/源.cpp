#include<stdio.h>
int MinInOrder(int r[], int p1, int p2)
{
	int result = r[p1];
	for (int i = p1 + 1; i <= p2; i++)
	{
		if (r[i] < result)
			result = r[i];
	}
	return result;
}
int Min(int r[],int length)
{
	if (r == NULL || length <= 0)
		return 0;
	int p1 = 0;
	int p2 = length - 1;
	int mid = p1;
	while (r[p1] >= r[p2])
	{
		if (p2 - p1 == 1)
		{
			mid = p2;
			break;
		}
		mid = (p1+p2) / 2;
		if (r[p1] == r[p2] && r[mid] == r[p2])
			return MinInOrder(r, p1, p2);
		if (r[mid] >= r[p1])
			p1 = mid;
		else if (r[mid] <=r[p2])
			p2 = mid;
	}
	return r[mid];
}

int main()
{
	int a[8] = {1,1,1,0,1};
	printf("%d\n", Min(a, 5));
	return 0;
}