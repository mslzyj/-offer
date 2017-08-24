/*
题目：一个整型数组里除了两个数字之外，其他数字都出现了两次，
      找出这两个只出现了一次的数字，要求时间复杂度为O(n)
*/
#include <cstdio>

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length)
{
	int num1;
	int num2;
	if (data == nullptr || length < 2)
		return;

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	num1 = num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
			num1 ^= data[j];
		else
			num2 ^= data[j];
	}
	printf("两个数字分别是: %d   %d\n",num1,num2);
}

// 找到num从右边数起第一个是1的位
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

// 判断数字num的第indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

int main(int argc, char* argv[])
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	FindNumsAppearOnce(data,8);
	return 0;
}