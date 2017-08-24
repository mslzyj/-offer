/*
题目：请实现一个函数，用来判断一个棵二叉树是不是对称的，如果一颗二叉树和它的镜像一样，
      那么它是对称的，否则不是。
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char value;
	struct node *lchild;
	struct node *rchild;
}TreeNode,*Tree;
//头插法创建二叉树
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
			printf("分配内存出错！");
			return NULL;
		}
		t->value = ch;
		CreateTree(t->lchild);
		CreateTree(t->rchild);
	}
	return t;
}
//求二叉树镜像
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
//先序递归遍历
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
	printf("创建二叉树，‘#’代表空：");
	T1=CreateTree(T);
	T2 = MirrorRecursively(T1);
	if (isSymmetrical(T1, T2))
		printf("是对称二叉树\n");
	else
		printf("不是对称二叉树\n");
	return 0;
}
/*
创建二叉树，‘#’代表空：ABC##D##BD##C##
是对称二叉树
请按任意键继续. . .
*/