/*
��Ŀ����һ������Ϊn������������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�
     ����֪���м��������ظ���Ҳ��֪��ÿ�������ظ��˼��Σ��ҳ�����������һ���ظ���
	 ���֡�
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