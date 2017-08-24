/*
��Ŀ������һ���������飬��������������Ҳ�и�����������һ���������Ķ���������
һ�������飬������������ĺ͵����ֵ����Ҫʱ�临�Ӷ�ΪO(n)��
��������{1��-2��3��10��-4��7��2��-5}��������������Ϊ{3��10��-4��7��2}
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
