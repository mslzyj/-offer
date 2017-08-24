/*
��Ŀ������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
���磺����12,��1��12��Щ�����а���1��������1��10��11��12��
1һ��������5�ˡ�
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

// ====================����һ====================
int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
	int number = 0;

	for (unsigned int i = 1; i <= n; ++i)
		number += NumberOf1(i);

	return number;
}

int NumberOf1(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
			number++;

		n = n / 10;
	}

	return number;
}

// ====================������====================
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int NumberOf1Between1AndN_Solution2(int n)
{
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf_s(strN, "%d", n);

	return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
		return 0;

	if (length == 1 && first > 0)
		return 1;

	// ����strN��"21345"
	// numFirstDigit������10000-19999�ĵ�һ��λ��1����Ŀ
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;

	// numOtherDigits��01346-21345���˵�һλ֮�����λ��1����Ŀ
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	// numRecursive��1-1345��1����Ŀ
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
		result *= 10;

	return result;
}

// ====================���Դ���====================

int main(int argc, char* argv[])
{
	int meth1, meth2;
	meth1=NumberOf1Between1AndN_Solution1(212345);
	meth2 = NumberOf1Between1AndN_Solution2(212345);
	printf("����һ��%d,��������%d\n", meth1, meth2);
	return 0;
}