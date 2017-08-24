#include <stdio.h>
#include "malloc.h"
struct ListNode
{
	int  value;
	ListNode *next;
};
//尾插法创建链表
ListNode *createList()
{
	ListNode *H = (ListNode *)malloc(sizeof(ListNode));
	H->next = NULL;
	ListNode *s, *r = H; //r指向尾节点，s为要插入的结点
	int x;
	scanf_s("%d",&x);
	while (x!=-1)
	{
		s = (ListNode *)malloc(sizeof(ListNode));
		s->value = x;
		s->next = r->next;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	return H;
}
void DeleteNode(ListNode **pListHead,ListNode *pToDelete)
{
	if (pListHead == NULL || *pListHead == NULL || pToDelete == NULL)
		return;
	//要删除的结点不是尾结点，将需要删除的结点后面的结点覆盖到要删除的结点，将后面的结点删除
	if (pToDelete->next != NULL)
	{
		ListNode *pNode = pToDelete->next;
		pToDelete->value = pNode->value;
		pToDelete->next = pNode->next;
		delete pNode;
		pNode = NULL;
	}
	//链表中只有一个结点，删除头结点（也是尾结点）
	else if (*pListHead == pToDelete)
	{
		delete pToDelete;
		pToDelete = NULL;
		pListHead = NULL;
	}
	//链表中有多个结点，要删除的结点在尾部，需要找到删除结点的前一个结点(常规方法)
	else
	{
		ListNode *pNodes = *pListHead;
		while (pNodes->next != pToDelete)
		{
			pNodes = pNodes->next;
		}
		pNodes->next = NULL;
		delete pToDelete;
		pToDelete = NULL;
	}
}
ListNode *find(ListNode *list, int x)
{
	ListNode *fq;
	fq = list->next;
	if (fq == NULL)
		return NULL;
	while (fq != NULL)
	{
		if (fq->value == x)
			return fq;
		fq = fq->next;
	}
	return NULL;
}

int main()
{
	int x;
	ListNode *p,*q;
	ListNode *H = (ListNode *)malloc(sizeof(ListNode));
	printf("输入单链表的结点值，以-1结束：");
	H = createList();
	printf("输入要删除的结点的值：");
	scanf_s("%d",&x);
	q = find(H,x);
	DeleteNode(&H,q);
	p = H->next;
	printf("删除一个结点%d后的值为 ：",x);
	while (p != NULL)
	{
		printf("%3d",p->value);
		p = p->next;
	}
	printf("\n");

	return 0;
}

/*
输入单链表的结点值，以-1结束：1 2 3 4 5 6 -1
输入要删除的结点的值：1
删除一个结点1后的值为 ：  2  3  4  5  6
请按任意键继续. . .

输入单链表的结点值，以-1结束：1 2 3 4 5 6 -1
输入要删除的结点的值：3
删除一个结点3后的值为 ：  1  2  4  5  6
请按任意键继续. . .

输入单链表的结点值，以-1结束：1 2 3 4 5 6 -1
输入要删除的结点的值：6
删除一个结点6后的值为 ：  1  2  3  4  5
请按任意键继续. . .
*/