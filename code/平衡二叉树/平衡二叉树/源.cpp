/*
��Ŀ������һ�Ŷ������ĸ��ڵ㣬�жϸ����ǲ���ƽ���������
      ���ĳ������������������������������1����ô������һ��ƽ���������
*/
#include <cstdio>
struct BinaryTreeNode
{
	int                    m_nValue;
	BinaryTreeNode*        m_pLeft;
	BinaryTreeNode*        m_pRight;
};
//����������
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
// ====================����1====================
int TreeDepth(const BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int nLeft = TreeDepth(pRoot->m_pLeft);
	int nRight = TreeDepth(pRoot->m_pRight);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool IsBalanced_Solution1(const BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return true;

	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);
	int diff = left - right;
	if (diff > 1 || diff < -1)
		return false;

	return IsBalanced_Solution1(pRoot->m_pLeft)
		&& IsBalanced_Solution1(pRoot->m_pRight);
}

// ====================����2====================
bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth);

bool IsBalanced_Solution2(const BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}

bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth)
{
	if (pRoot == nullptr)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left)
		&& IsBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

int main()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	bool meth1 = IsBalanced_Solution1(pNode1);
	if (meth1)
		printf("����һ����ƽ�������\n");
	else
		printf("����һ������ƽ�������\n");

	bool meth2 = IsBalanced_Solution2(pNode1);
	if (meth2)
		printf("����������ƽ�������\n");
	else
		printf("������������ƽ�������\n");

	return 0;
}