/*
��Ŀ��дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�ã������������� ����������š�
*/
#include <cstdio>

int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}
int main()
{
	printf("%d\n", Add(3,30));
	return 0;
}