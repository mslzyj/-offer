#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//树结构
typedef struct tree
{
	ElemType data;
	struct tree * lchild;
	struct tree * rchild;
}TreeNode, *Tree;

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
		t->data = ch;
		CreateTree(t->lchild);
		CreateTree(t->rchild);
	}
	return t;
}
bool DoedTreeHaveTree(Tree pRoot1,Tree pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->data != pRoot2->data)
		return false;
	return DoedTreeHaveTree(pRoot1->lchild, pRoot2->lchild) && DoedTreeHaveTree(pRoot1->rchild,pRoot2->rchild);
}
bool HasSubtree(Tree pRoot1,Tree pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->data == pRoot2->data)
			result = DoedTreeHaveTree(pRoot1,pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->lchild,pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->rchild,pRoot2);
	}
	return result;
}
int main()
{
	Tree T1 = (Tree)malloc(sizeof(TreeNode));
	bool result=false;
	printf("\n按先序序列输入A树结点序列，'#'代表空：");
	T1=CreateTree(T1);
	fflush(stdin);   //清除缓存，此语句很重要
	Tree T2 = (Tree)malloc(sizeof(TreeNode));
	printf("\n按先序序列输入B树结点序列，'#'代表空：");
	T2 = CreateTree(T2);
	result = HasSubtree(T1,T2);
	printf("\n");
	if (result == true)
	   printf("B是A的子结构\n\n");
	else
		printf("B不是A的子结构\n\n");
	return 0;
}
/*

按先序序列输入A树结点序列，'#'代表空：ABD##EF##G##C##
按先序序列输入B树结点序列，'#'代表空：BD##E##
B是A的子结构
请按任意键继续. . .

按先序序列输入A树结点序列，'#'代表空：ABD##EF##G##C##
按先序序列输入B树结点序列，'#'代表空：#
B不是A的子结构
请按任意键继续. . .

按先序序列输入A树结点序列，'#'代表空：#
按先序序列输入B树结点序列，'#'代表空：BD##E##
B不是A的子结构
请按任意键继续. . .

按先序序列输入A树结点序列，'#'代表空：ABD##EF##G##C##
按先序序列输入B树结点序列，'#'代表空：fq##n##
B不是A的子结构
请按任意键继续. . .


按先序序列输入A树结点序列，'#'代表空：ABD##EF##G##C##
按先序序列输入B树结点序列，'#'代表空：A##
B是A的子结构
请按任意键继续. . .
*/

