#include<stdio.h>
#include"malloc.h"
typedef struct node
{
	struct node *next;
	int data;
}*ListNode;

//尾插法创建链表(不带头结点)
ListNode creatrList()
{
	ListNode p = (ListNode)malloc(sizeof(ListNode));
	ListNode s,q;
	p ->next = NULL;
	q = p;
	int x=0;
	printf("创建链表，以-1结束：");
	scanf_s("%d", &x);
	while (x!=-1)
	{
		s = (ListNode)malloc(sizeof(ListNode));
		s->next = NULL;
		p->data = x;
		p->next = s;
		p = s;
		scanf_s("%d", &x);
	}
	return q;
}
//反转链表
ListNode ReverseList(ListNode pHead)
{
	ListNode prev = NULL;
	ListNode pNode = pHead;
	ListNode ReverPHead=NULL;
	while (pNode != NULL)
	{
		ListNode pNext = pNode->next;
		if (pNext == NULL)
			ReverPHead = pNode;
		pNode->next = prev;
		prev = pNode;
		pNode = pNext;
	}
	printf("%d",ReverPHead->data);
	return ReverPHead;
}

int main()
{
	ListNode h,RH;
	h = creatrList();

	RH=ReverseList(h);
	if (RH->next == NULL)
		printf("链表为空\n");
	else
	{
		RH = RH->next;
		while (RH != NULL)
		{
			printf("%3d", RH->data);
			RH = RH->next;
		}
		printf("\n");
	}
	return 0;

}
/*
创建链表，以-1结束：1 2 3 4 5 6 -1
6  5  4  3  2  1
请按任意键继续. . .

创建链表，以-1结束：-1
链表为空
请按任意键继续. . .

创建链表，以-1结束：4 -1
4
请按任意键继续. . .
*/