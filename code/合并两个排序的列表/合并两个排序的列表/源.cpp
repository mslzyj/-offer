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
	ListNode s, q;
	p->next = NULL;
	q = p;
	int x = 0;
	scanf_s("%d", &x);
	while (x != -1)
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
//�ϲ���������
ListNode Merge(ListNode AList,ListNode BList)
{
	if (AList->next == NULL)
		return BList;
	else if (BList->next == NULL)
		return AList;
	ListNode CList = NULL;
	if (AList->data < BList->data)
	{
		CList = AList;
     	CList->next = Merge(AList->next,BList);
	}
	else
	{
		CList = BList;
		CList->next = Merge(AList, BList->next);
	}
	return CList;
}

int main()
{
	ListNode AList, BList,CList;
	printf("����A������-1������");
	AList = creatrList();
	printf("����B������-1������");
	BList = creatrList();
	CList = Merge(AList, BList);
	printf("�ϲ�����б�Ϊ:");
	while (CList->next!=NULL)
	{
		printf("%3d",CList->data);
		CList = CList->next;
	}
	printf("\n");
	return 0;

}
/*
����A������-1������1 2 3 5 6 7 -1
����B������-1������8 9 11 14 16 19 21 23 25 27 -1
�ϲ�����б�Ϊ:  1  2  3  5  6  7  8  9 11 14 16 19 21 23 25 27
�밴���������. . .

����A������-1������-1
����B������-1������1 2 3 4 5 6 7 8 -1
�ϲ�����б�Ϊ:  1  2  3  4  5  6  7  8
�밴���������. . .

����A������-1������1 2 3 4 5 6 7 8 -1
����B������-1������1 2 3 4 5 6 7 8 -1
�ϲ�����б�Ϊ:  1  1  2  2  3  3  4  4  5  5  6  6  7  7  8  8
�밴���������. . .


*/
