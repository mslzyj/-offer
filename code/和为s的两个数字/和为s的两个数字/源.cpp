/*
题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得他们的和正好是s。
      如果有多对数字的和等于s，输出任意一对即可。
*/
#include <cstdio>

bool FindNumbersWithSum(int data[], int length, int sum)
{
	int num1=0;
	int num2=0;
	bool found = false;
	if (length < 1 )
		return found;

	int ahead = length - 1;
	int behind = 0;

	while (ahead > behind)
	{
		long long curSum = data[ahead] + data[behind];

		if (curSum == sum)
		{
			num1 = data[behind];
			num2 = data[ahead];
			found = true;
			break;
		}
		else if (curSum > sum)
			ahead--;
		else
			behind++;
	}
	printf("两个数分别是： %d  %d\n",num1,num2);
	return found;
}

int main()
{   
	int data[] = { 1, 2, 4, 7, 11, 15 };
	FindNumbersWithSum(data,6,15);
	return 0;
}