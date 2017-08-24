#include<stdio.h>
bool isEven(int n)
{
	return (n & 1) == 0;
}
void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == NULL || length == 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin)) //���ǰ���ָ��ָ�������������
			pBegin++;
		while (pBegin < pEnd && func(*pEnd))    //��������ָ��ָ���������ż��
			pEnd--;
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
	
}
int main()
{
	int a[8] = { 5, 1, 6, 2, 3, 7, 8, 10 };
	Reorder(a,8,isEven);
	for (int i = 0; i < 8; i++)
		printf("%3d",a[i]);
	printf("\n");
	return 0;
}
/*
5  1  7  3  2  6  8 10
�밴���������. . .
*/