/*
��Ŀ���ַ�������ת����ʱ���ַ���ǰ�����ɸ��ַ���ת�Ƶ��ַ�����β����
���������ַ���"abcdef"������2�����"cdefgab"
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

			// ��ת�ַ�����ǰ��n���ַ�
			Reverse(pFirstStart, pFirstEnd);
			// ��ת�ַ����ĺ��沿��
			Reverse(pSecondStart, pSecondEnd);
			// ��ת�����ַ���
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