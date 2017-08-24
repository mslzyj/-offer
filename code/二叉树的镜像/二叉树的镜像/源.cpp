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
int main()
{
	Tree T;
	printf("��������������#������գ�");
	CreateTree(T);
	printf("���������������");
	PreOrder(T);
	MirrorRecursively(T);
	if (T)
	{
		printf("\n����������������: ");
		PreOrder(T);
	}
	else
		printf("��������Ϊ��");
	printf("\n");
	return 0;
}
/*
��������������#������գ�ABD##E##CF##G##
���������������ABDECFG
����������������: ACGFBED
�밴���������. . .

��������������#������գ�#
�����������������������Ϊ��
�밴���������. . .

*/