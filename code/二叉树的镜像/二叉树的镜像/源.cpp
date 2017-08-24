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
void MirrorRecursively(Tree pNpde)
{
	if (pNpde == NULL)
		return ;
	if (pNpde->lchild == NULL && pNpde->rchild == NULL)
		return ;
	Tree pTemp = pNpde->lchild;
	pNpde->lchild = pNpde->rchild;
	pNpde->rchild = pTemp;
	if (pNpde->lchild)
		MirrorRecursively(pNpde->lchild);
	if (pNpde->rchild)
		MirrorRecursively(pNpde->rchild);
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
int main()
{
	Tree T;
	printf("创建二叉树，‘#’代表空：");
	CreateTree(T);
	printf("先序遍历二叉树：");
	PreOrder(T);
	MirrorRecursively(T);
	if (T)
	{
		printf("\n先序遍历镜像二叉树: ");
		PreOrder(T);
	}
	else
		printf("创建的树为空");
	printf("\n");
	return 0;
}
/*
创建二叉树，‘#’代表空：ABD##E##CF##G##
先序遍历二叉树：ABDECFG
先序遍历镜像二叉树: ACGFBED
请按任意键继续. . .

创建二叉树，‘#’代表空：#
先序遍历二叉树：创建的树为空
请按任意键继续. . .

*/