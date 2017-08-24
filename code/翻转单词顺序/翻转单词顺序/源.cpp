/*
题目：输入一个英文句子，翻转句子中单词的顺序，但待查内字符的顺序不变。
      标点符号和普通字母一样处理，例如输入“I am student.”输出“student. a am I”。
*/
#include <cstdio>
#include <string>

void Reverse(char *pBegin,char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;
	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}
char* ReverseSentence(char *pData)
{
	if (pData == nullptr)
		return nullptr;

	char *pBegin = pData;

	char *pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	// 翻转整个句子
	Reverse(pBegin, pEnd);

	// 翻转句子中的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}

	return pData;
}
int main()
{
	char s[] = "I am a student.";
	char *s1;
	s1 = ReverseSentence(s);
	printf("%s\n",s1);
	return 0;
}