#include<stdio.h>
long long Fibonacci(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n-1) + Fibonacci(n-2);
}
long f1(int n)
{
	long long x = 0, y = 1;
	for (int i = 1; i < n; i++)
	{
		y = x + y; //��ǰ��ֵ����ǰ����֮��
		x = y - x; //��ǰ���ǰһ����ڵ�ǰ���ȥ��ǰ���ǰһ���ǰһ��
	}
	return y;
}
int main()
{ 
	int n;
	long  long result;
	scanf_s("%d",&n);
	result = f1(n);
	printf("%d\n",result);
}