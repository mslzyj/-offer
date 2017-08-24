/*
题目：在一个长度为n的数组里面的所有数字都在0到n-1的范围内。数组中某些数字是重复的，
     但不知道有几个数字重复，也不知道每个数字重复了几次，找出数组中任意一个重复的
	 数字。
*/
#include<stdio.h>
int  duplication(int number[],int length)
{
	int rnumber=-1;
	if (number == NULL || length < 0)
		return -1;
	for (int i = 0; i < length; i++)
	{
		if (number[i] <0 || number[i]>length - 1)
			return -1;
	}
	for (int i = 0; i < length - 1; i++)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				rnumber = number[i];
				return rnumber;
			}
			int temp = number[i];
			number[i] = number[temp];
			number[temp] = temp;
		}
	}
	return -1;
}
int main()
{
	int numbers[] = {2,3,1,0,2,5,3};
	printf("%d\n", duplication(numbers, 7));
	return 0;
}