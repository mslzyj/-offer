/*
��Ŀ������һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
      ����ж�����ֵĺ͵���s���������һ�Լ��ɡ�
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
	printf("�������ֱ��ǣ� %d  %d\n",num1,num2);
	return found;
}

int main()
{   
	int data[] = { 1, 2, 4, 7, 11, 15 };
	FindNumbersWithSum(data,6,15);
	return 0;
}