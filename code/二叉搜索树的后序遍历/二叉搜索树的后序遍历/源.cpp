#include<stdio.h>
bool VerifySequenceOfBST(int squence[], int length)
{
	if (squence == NULL || length < 0)
		return false;
	int root = squence[length - 1];
	//在二叉搜索树中左子节点小于根节点
	int i;
	for (i=0; i < length-1; ++i)
	{
		if (squence[i] > root)
			break;
	}
	//在二叉搜索树中右子节点大于根节点
	int j;
	for (j=i; j < length - 1;++j)
	{
		if (squence[j]< root)
			return false;
	}
	//判断左子数是不是二叉搜索树
	bool left = true;
	if (i>0)
		left = VerifySequenceOfBST(squence,i);
   //判断右子数是不是二叉搜索树
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
		printf("是\n");
	else
		printf("不是\n");
	return 0;
}