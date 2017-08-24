/*
��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
      �����ź���ͨ��ĸһ�������������롰I am student.�������student. a am I����
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

	// ��ת��������
	Reverse(pBegin, pEnd);

	// ��ת�����е�ÿ������
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