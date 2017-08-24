#include <cstdio>
#include <string>
/*
题目：在字符串中找出第一个只出现一次的字符
*/
char FirstNotRepeatingChar(const char* pString)
{
	if (pString == nullptr)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;

	const char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)] ++;

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		pHashKey++;
	}

	return '\0';
}
int main(int argc, char* argv[])
{
	char a[] = "ajhvbsuavbjuaidsa";
	printf("%c\n", FirstNotRepeatingChar(a));
	return 0;
}