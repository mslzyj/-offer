#include <stdio.h>
#include<stdlib.h>
#include<vector>
typedef int TreeType;
typedef struct tree
{
	TreeType value;
	struct tree *left;
	struct tree *right;
}TreeNode;
//����������
TreeNode * Create(TreeNode *T)
{
	TreeType data;
	scanf_s("%d",&data);
	if (data == 0)
		T = NULL;
	else
	{
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (!T)
		{
			printf("�����ڴ�ʧ��");
			return NULL;
		}
		else{
			T->value = data;
			T->left=Create(T->left);
			T->right=Create(T->right);
		}
	}
	return T;
}
void FindPath(TreeNode*   pRoot,int  expectedSum, std::vector<int>& path,int  currentSum)
{
	currentSum += pRoot->value;
	path.push_back(pRoot->value);

	// �����Ҷ��㣬����·���Ͻ��ĺ͵��������ֵ
	// ��ӡ������·��
	bool isLeaf = pRoot->left == NULL && pRoot->right == NULL;
	if (currentSum == expectedSum && isLeaf)
	{
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
			printf("%3d", *iter);
		printf("\n");
	}
	// �������Ҷ��㣬����������ӽ��
	if (pRoot->left != NULL)
		FindPath(pRoot->left, expectedSum, path, currentSum);
	if (pRoot->right != NULL)
		FindPath(pRoot->right, expectedSum, path, currentSum);

	// �ڷ��ص������֮ǰ����·����ɾ����ǰ��㣬
	// ����currentSum�м�ȥ��ǰ����ֵ
	currentSum -= pRoot->value;
	path.pop_back();
}

void FindPath(TreeNode* pRoot, int expectedSum)
{
	if (pRoot == NULL)
		return;
	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}
//����
void PreOrder(TreeNode *T)
{
	if (T)
	{
		printf("%3d", T->value);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
int main()
{
	TreeNode *T =(TreeNode*) malloc(sizeof(TreeNode));
	T=Create(T);
	FindPath(T,22);
	printf("\n");
	//PreOrder(T);
	//printf("\n");
	return 0;
}
/*
10 5 4 0 0 7 0 0 12 0 0
A path is found:  10  5  7
A path is found:  10 12
�밴���������. . .
*/