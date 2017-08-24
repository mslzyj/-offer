/*
��Ŀ������һ������s����ӡ�����к�Ϊs�������������У����ٺ�������������
     ����;����15������1+2+3+4+5=4+5+6=7+8�����Դ�ӡ��3�����������С�
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
