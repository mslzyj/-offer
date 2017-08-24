#include <stdio.h>
bool g_InvalidInput = false;  //������ʱ���������Ϊtrue������Ϊfalse���������԰ѷ���ֱֵ�Ӵ�����������
//�Ƚ��������Ƿ����
bool equal(double num1,double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; i++)
		result *= base;
	return result;
}
//PowerWithUnsignedExponent()�����Ľ���
double PowerWithUnsignedExponent1(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignedExponent1(base, exponent >> 1);  //���ƴ������2
	result *= result;
	if (exponent & 0x1 == 1)  //�������������
		result *= base;
	return result;
}
double power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0){
		g_InvalidInput = true;  //����ʱ��g_InvalidInput = false;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int )(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	double result = PowerWithUnsignedExponent1(base,absExponent);
	if (exponent < 0)
		result = 1.0 / result;  //ָ��Ϊ�������Խ������
	return result;
}
int main()
{
	double base, exponent;
	scanf_s("%lf", &base);
	scanf_s("%lf", &exponent);
	printf("%lf\n", power(base, exponent));
	return 0;
}
/*
2.0 3.0
8.000000
�밴���������. . .

2.0 -3.0
0.125000
�밴���������. . .

0 0
1.000000
�밴���������. . .

*/