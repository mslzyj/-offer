#include <stdio.h>
#include "malloc.h"
struct ListNode
{
	int  value;
	ListNode *next;
};
//β�巨��������
ListNode *createList()
{
	ListNode *H = (ListNode *)malloc(sizeof(ListNode));
	H->next = NULL;
	ListNode *s, *r = H; //rָ��β�ڵ㣬sΪҪ����Ľ��
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
	printf("���뵥����Ľ��ֵ����-1������");
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

