/*
题目：输入一个整数s，打印出所有和为s的连续正数序列（至少含有两个数）。
     例如;输入15，由于1+2+3+4+5=4+5+6=7+8，所以打印出3个连续的序列。
*/
#include <stdio.h>
void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d ", i);

	printf("\n");
}

void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
			PrintContinuousSequence(small, big);

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}

		big++;
		curSum += big;
	}
}
int main()
{
	int sum = 15;
	FindContinuousSequence(sum);
	return 0;
}
