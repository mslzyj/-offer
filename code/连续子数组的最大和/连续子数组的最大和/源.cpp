/*
题目：输入一个整型数组，数组里面有正数也有负数，数组中一个或连续的多个整数组成
一个子数组，求所有子数组的和的最大值，需要时间复杂度为O(n)。
例如输入{1，-2，3，10，-4，7，2，-5}，和最大的子数组为{3，10，-4，7，2}
*/
#include <cstdio>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if ((pData == nullptr) || (nLength <= 0))
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < nLength; ++i)
	{
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}

	return nGreatestSum;
}
int main()
{
	const int length = 8;
	int a[length] = { 1, -2,3, 10, -4, 7, 2, -5 };
	int result = FindGreatestSumOfSubArray(a, length);
	printf("%d\n",result);
	return 0;
}
