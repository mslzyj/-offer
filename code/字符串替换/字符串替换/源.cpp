#include <stdio.h>
/*
���ַ����еĿո��滻��%20�����³���ʱ�临�Ӷ�ΪO(n)
*/

void ReplaceBlank(char *string, int length)
{
	if (string == NULL || length > 0)
		return;
	int originalLength = 0;
	int nubverOfBlank = 0;
	while (string[originalLength] != '\0')
	{
		if (string[originalLength] == ' ')
			++nubverOfBlank;
		++originalLength;
	
	}
	int newLength = originalLength + nubverOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = originalLength-1;
	int indexOfNew = newLength-1;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal == ' '])
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}
int main()
{
	const int length = 13;
	char string[length] = "we are happy";
	ReplaceBlank(string,length);
	printf("%s", string);
	return 0;
	
}
/*
#include <stdio.h>
#include <assert.h>
void replace(char *src)
{
assert(src);
int OldLen = 0;                  //ԭ�ַ�������
int NewLen = 0;                  //���ַ�������
int BlackNum = 0;                //�ո�����
int NewBack = 0;                 //���ַ���β��
int OldBack = 0;                 //ԭ�ַ���β��
while (src[OldLen] != '\0')
{
if (src[OldLen] == ' ')
{
BlackNum++;
}
OldLen++;
}
NewLen = OldLen + BlackNum * 2;
OldBack = OldLen-1;
NewBack = NewLen - 1;
while (OldBack!=0)
{
if (src[OldBack] == ' ')
{
src[NewBack--] = '0';
src[NewBack--] = '2';
src[NewBack] = '%';
}
else
{
src[NewBack] = src[OldBack];
}
OldBack--;
NewBack--;
}}
}
int main()
{
char p[20] = "hello world !";
replace(p);
printf("%s\n", p);
return 0;
return 0;
}


*/