/*
��Ŀ����ʵ��һ�������������ж�һ���ö������ǲ��ǶԳƵģ����һ�Ŷ����������ľ���һ����
      ��ô���ǶԳƵģ������ǡ�
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char value;
	struct node *lchild;
	struct node *rchild;
}TreeNode,*Tree;
//ͷ�巨����������
Tree CreateTree(Tree &t)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		t = NULL;
	else
	{
		t = (Tree)malloc(sizeof(TreeNode));
		if (!t)
		{
			printf("�����ڴ����");
			return NULL;
		}
		t->value = ch;
		CreateTree(t->lchild);
		CreateTree(t->rchild);
	}
	return t;
}
//�����������
Tree MirrorRecursively(Tree pNpde)
{
	if (pNpde == NULL)
		return NULL;
	if (pNpde->lchild == NULL && pNpde->rchild == NULL)
		return NULL;
	Tree pTemp = pNpde->lchild;
	pNpde->lchild = pNpde->rchild;
	pNpde->rchild = pTemp;
	if (pNpde->lchild)
		MirrorRecursively(pNpde->lchild);
	if (pNpde->rchild)
		MirrorRecursively(pNpde->rchild);
	return pNpde;
}
//����ݹ����
void PreOrder(Tree T)
{
	if (T)
	{
		printf("%c",T->value);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
bool isSymmetrical1(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->value != pRoot2->value)
		return false;

	return isSymmetrical1(pRoot1->lchild, pRoot2->lchild)
		&& isSymmetrical1(pRoot1->lchild, pRoot2->lchild);
}
bool isSymmetrical(TreeNode* pRoot, TreeNode* pRoot1)
{
	return isSymmetrical1(pRoot, pRoot1);
}
int main()
{
	Tree T,T1,T2;
	printf("��������������#������գ�");
	T1=CreateTree(T);
	T2 = MirrorRecursively(T1);
	if (isSymmetrical(T1, T2))
		printf("�ǶԳƶ�����\n");
	else
		printf("���ǶԳƶ�����\n");
	return 0;
}
/*
��������������#������գ�ABC##D##BD##C##
�ǶԳƶ�����
�밴���������. . .
*/