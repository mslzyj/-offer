#include<stdio.h>
#include"malloc.h"
typedef struct node
{
	struct node *next;
	int data;
}*ListNode;

//β�巨��������(����ͷ���)
ListNode creatrList()
{
	ListNode p = (ListNode)malloc(sizeof(ListNode));
	ListNode s,q;
	p ->next = NULL;
	q = p;
	int x=0;
	printf("����������-1������");
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
//��ת����
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
		printf("����Ϊ��\n");
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
����������-1������1 2 3 4 5 6 -1
6  5  4  3  2  1
�밴���������. . .

����������-1������-1
����Ϊ��
�밴���������. . .

����������-1������4 -1
4
�밴���������. . .
*/