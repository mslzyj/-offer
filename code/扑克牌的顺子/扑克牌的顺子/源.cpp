/*
��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
       2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�
*/
#include <cstdio>
#include <cstdlib>

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int* numbers, int length)
{
	if (numbers == nullptr || length < 1)
		return false;

	qsort(numbers, length, sizeof(int), Compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	// ͳ��������0�ĸ���
	for (int i = 0; i < length && numbers[i] == 0; ++i)
		++numberOfZero;

	// ͳ�������еļ����Ŀ
	int small = numberOfZero;
	int big = small + 1;
	while (big < length)
	{
		// ��������ȣ��ж��ӣ���������˳��
		if (numbers[small] == numbers[big])
			return false;

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}

int Compare(const void *arg1, const void *arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}


int main(int argc, char* argv[])
{
	int numbers[] = { 0, 3, 2, 6,4 };
	if (IsContinuous(numbers, 5))
		printf("��˳��\n");
	else
		printf("����˳��\n");
	return 0;
}
