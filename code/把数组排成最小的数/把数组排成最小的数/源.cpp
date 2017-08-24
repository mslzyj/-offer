/*
��Ŀ������һ�����������飬�������������е�����ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
���磺��������{3��32��321}�����ӡ����3�������ųɵ���С����321323.
*/
#include "cstdio"
#include <string>
#include <algorithm>
#include<stdio.h>

int compare(const void* strNumber1, const void* strNumber2);

// int��������ʮ���Ʊ�ʾ���ֻ��10λ
const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

void PrintMinNumber(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; ++i)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; ++i)
		printf("%s", strNumbers[i]);
	printf("\n");

	for (int i = 0; i < length; ++i)
		delete[] strNumbers[i];
	delete[] strNumbers;
}

// ���[strNumber1][strNumber2] > [strNumber2][strNumber1], ����ֵ����0
// ���[strNumber1][strNumber2] = [strNumber2][strNumber1], ����ֵ����0
// ���[strNumber1][strNumber2] < [strNumber2][strNumber1], ����ֵС��0
int compare(const void* strNumber1, const void* strNumber2)
{
	// [strNumber1][strNumber2]
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	// [strNumber2][strNumber1]
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

int main(int argc, char* argv[])
{
	int numbers[] = { 3, 323, 32123 };
	PrintMinNumber(numbers,3);
	return 0;
}