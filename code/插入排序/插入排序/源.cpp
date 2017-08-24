#include <stdio.h>
#include <string.h>

//直接插入排序
void InsertSort(int arr[], int length)
{
	int j;
	for (int i = 2; i <length; i++)
	{

		arr[0] = arr[i];
		for (j = i - 1; arr[0] < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = arr[0];

	}

}
//改进后的直接插入排序
void insertSort1(int arr[], int length)
{
	for (int i = 2; i < length; i++)
	{
		int j;
		if (arr[i] < arr[i - 1])
		{
			arr[0] = arr[i];
			for (j = i - 1; arr[0] < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}
}

void BiInsertSort(int arr[], int length)
{
	for (int i = 2; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			arr[0] = arr[i];
			int low = 1, high = i - 1, mid;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (arr[0] < arr[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j = i - 1; j >= low; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[low] = arr[0];

		}
	}
}
int main()
{
	int a[8] = { 0, 2, 1, 4, 3, 8, 3, 9 };
	InsertSort(a, 8);
	for (int i = 1; i < 8; i++)
		printf("%3d", a[i]);
	printf("\n");
	insertSort1(a, 8);
	for (int i = 1; i < 8; i++)
		printf("%3d", a[i]);
	printf("\n");
	BiInsertSort(a, 8);
	for (int i = 1; i < 8; i++)
		printf("%3d", a[i]);
	printf("\n");
	return 0;
}