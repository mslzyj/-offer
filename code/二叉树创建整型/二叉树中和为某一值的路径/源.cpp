
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *ltree;
	struct node *rtree;
}TNode;
//ADT of the Binary tree
TNode * create(TNode *);
int depth(TNode *);
int findmax(int, int);
void postorder(TNode *);
void inorder(TNode *);
void preorder(TNode *);
int main()
{
	TNode *tree=NULL;
	printf("BinaryTree (By Recursion)\n\n");
	tree = create(tree);
	printf("\npreorder:\n");
	preorder(tree);
	printf("\ninorder:\n");
	inorder(tree);
	printf("\npostorder:\n");
	postorder(tree);
	printf("\nThe depth o the binary tree is: %d.\n", depth(tree));
	return 0;
}//main
TNode * create(TNode * p)
{//创建一棵二叉树，返回根节点地址
	int num;
	scanf_s("%d", &num);
	if (num == 0){
		return NULL;
	}//if
	p = (TNode *)malloc(sizeof(TNode));
	p->data = num;//把数据赋值给数据域
	p->ltree = create(p->ltree);//递归算法，创建左子树
	p->rtree = create(p->rtree);
	return p;
}//create
void preorder(TNode * p)
{
	TNode* tree = p;
	if (tree){
		printf("%5d", p->data);
		preorder(p->ltree);
		preorder(p->rtree);
	}
}//preorder
void inorder(TNode * p)
{
	TNode* tree = p;
	if (tree){
		inorder(p->ltree);
		printf("%5d", p->data);
		inorder(p->rtree);
	}
}//inorder
void postorder(TNode * p)
{
	TNode* tree = p;
	if (tree){
		postorder(p->ltree);
		postorder(p->rtree);
		printf("%5d", p->data);
	}
}//postorder
int findmax(int x, int y)
{
	return (x>y ? x : y);
}//findmax
int depth(TNode * p)
{
	TNode * tree = p;
	int dep = 0;
	int depl, depr;
	if (!p){
		return 0;
	}
	depl = depth(p->ltree);
	depr = depth(p->rtree);
	dep = 1 + findmax(depl, depr);
	return dep;
}//depth
