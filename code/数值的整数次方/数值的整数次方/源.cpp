#include <stdio.h>
bool g_InvalidInput = false;  //当出错时，这个变量为true，否则为false，这样可以把返回值直接传给其他变量
//比较两个数是否相等
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
//PowerWithUnsignedExponent()方法改进版
double PowerWithUnsignedExponent1(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignedExponent1(base, exponent >> 1);  //右移代替除以2
	result *= result;
	if (exponent & 0x1 == 1)  //与代替求余运算
		result *= base;
	return result;
}
double power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0){
		g_InvalidInput = true;  //出错时，g_InvalidInput = false;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int )(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	double result = PowerWithUnsignedExponent1(base,absExponent);
	if (exponent < 0)
		result = 1.0 / result;  //指数为负数，对结果求倒数
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
请按任意键继续. . .

2.0 -3.0
0.125000
请按任意键继续. . .

0 0
1.000000
请按任意键继续. . .

*/