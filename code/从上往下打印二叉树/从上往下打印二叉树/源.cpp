#include<stdio.h>
#include<stack>
typedef struct tree
{
	char value;
	struct tree *lchild;
	struct tree *rchild;
}*Tree;
//创建二叉树
void CreateTree(Tree &t)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		t = NULL;
	else
	{
		t = (Tree)malloc(sizeof(Tree));
		if (!t)
		{
			printf("分配内存出错！");
			return;
		}
		t->value = ch;
		CreateTree(t->lchild);
		CreateTree(t->rchild);
	}
}

//层次遍历(从上往下打印二叉树)
void printfFromTopToBottom(Tree &pRoot)
{
	if (!pRoot)
		return;
	std::deque<Tree>dequeTreeNode;
	dequeTreeNode.push_back(pRoot);
	while (dequeTreeNode.size())
	{
		Tree pNpde = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%c", pNpde->value);
		if (pNpde->lchild)
			dequeTreeNode.push_back(pNpde->lchild);
		if (pNpde->rchild)
			dequeTreeNode.push_back(pNpde->rchild);
	}
}

int main()
{
	Tree T=NULL;
	CreateTree(T);
	printfFromTopToBottom(T);
	printf("\n");
	return 0;
}
/*
  AB#DG###CE##FH###
  ABCDEFGH
  请按任意键继续. . .

*/