/*
题目：字符串的旋转操作时把字符串前面若干个字符串转移到字符串的尾部。
例如输入字符串"abcdef"和数字2，输出"cdefgab"
*/
#include<stdio.h>
#include<string.h>
void Reverse(char *pBegin,char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;
	while (pBegin<pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != nullptr)
	{
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			// 翻转字符串的前面n个字符
			Reverse(pFirstStart, pFirstEnd);
			// 翻转字符串的后面部分
			Reverse(pSecondStart, pSecondEnd);
			// 翻转整个字符串
			Reverse(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}
int main()
{
	char s[] = "abc gdefgh.";
	char *s1;
	s1 = LeftRotateString(s,5);
	printf("%s\n",s1);

}