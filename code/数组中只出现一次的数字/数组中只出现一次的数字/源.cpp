/*
��Ŀ��һ�����������������������֮�⣬�������ֶ����������Σ�
      �ҳ�������ֻ������һ�ε����֣�Ҫ��ʱ�临�Ӷ�ΪO(n)
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
	printf("�������ֱַ���: %d   %d\n",num1,num2);
}

// �ҵ�num���ұ������һ����1��λ
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

// �ж�����num�ĵ�indexBitλ�ǲ���1
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