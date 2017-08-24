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
	scanf_s("%d", &x);
	while (x != -1)
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

int main()
{
	ListNode *H = (ListNode *)malloc(sizeof(ListNode)),*p;
	printf("输入单链表的结点值，以-1结束：");
	H = createList();
	p = H->next;
	while (p != NULL)
	{
		printf("%3d", p->value);
		p = p->next;
	}
	printf("\n");
	return 0;
}

