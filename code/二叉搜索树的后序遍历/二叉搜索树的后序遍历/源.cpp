#include<stdio.h>
bool VerifySequenceOfBST(int squence[], int length)
{
	if (squence == NULL || length < 0)
		return false;
	int root = squence[length - 1];
	//�ڶ��������������ӽڵ�С�ڸ��ڵ�
	int i;
	for (i=0; i < length-1; ++i)
	{
		if (squence[i] > root)
			break;
	}
	//�ڶ��������������ӽڵ���ڸ��ڵ�
	int j;
	for (j=i; j < length - 1;++j)
	{
		if (squence[j]< root)
			return false;
	}
	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i>0)
		left = VerifySequenceOfBST(squence,i);
   //�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i<length - 1)
		right = VerifySequenceOfBST(squence+i, length-i-1);
	return (left && right);
}
int main()
{   
	const int length = 7;
	int tree[length] = { 5, 7, 6, 9, 11, 10, 8 };
	if (VerifySequenceOfBST(tree, length))
		printf("��\n");
	else
		printf("����\n");
	return 0;
}