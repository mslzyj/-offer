#include <stdio.h>
#include<stdbool.h>
int main()
{
	int find(int  matrix[4][4], int rows, int columns, int number);
	int a[4][4] = {{ 1, 2, 8, 9 }, 
	               { 2, 4, 9, 12 }, 
				   { 4, 7, 10, 13 }, 
	               { 6, 8, 11, 15 } };
	int result = find(a, 4, 4, 12);
	if (result == 1)
		printf("已经查到\n");
	else
		printf("数组中没有此元素\n");
	return 0;
}
int find(int  matrix[4][4], int rows, int columns, int number)
{
	bool found = false;
	if (matrix != NULL && rows>0 && columns>0)
	{
		int a = 0;
		int b = columns - 1;
		while (a<rows && b >= 0)
		{
			if (matrix[a][b] == number)
			{
				found = true;
				break;
			}
			else if (matrix[a][b]> number)
				--b;
			else
				++a;
		}
	}
	return found;
}