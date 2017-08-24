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
//合并两个链表
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
	printf("创建A链表，以-1结束：");
	AList = creatrList();
	printf("创建B链表，以-1结束：");
	BList = creatrList();
	CList = Merge(AList, BList);
	printf("合并后的列表为:");
	while (CList->next!=NULL)
	{
		printf("%3d",CList->data);
		CList = CList->next;
	}
	printf("\n");
	return 0;

}
/*
创建A链表，以-1结束：1 2 3 5 6 7 -1
创建B链表，以-1结束：8 9 11 14 16 19 21 23 25 27 -1
合并后的列表为:  1  2  3  5  6  7  8  9 11 14 16 19 21 23 25 27
请按任意键继续. . .

创建A链表，以-1结束：-1
创建B链表，以-1结束：1 2 3 4 5 6 7 8 -1
合并后的列表为:  1  2  3  4  5  6  7  8
请按任意键继续. . .

创建A链表，以-1结束：1 2 3 4 5 6 7 8 -1
创建B链表，以-1结束：1 2 3 4 5 6 7 8 -1
合并后的列表为:  1  1  2  2  3  3  4  4  5  5  6  6  7  7  8  8
请按任意键继续. . .


*/
