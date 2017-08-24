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
	//Ҫɾ���Ľ�㲻��β��㣬����Ҫɾ���Ľ�����Ľ�㸲�ǵ�Ҫɾ���Ľ�㣬������Ľ��ɾ��
	if (pToDelete->next != NULL)
	{
		ListNode *pNode = pToDelete->next;
		pToDelete->value = pNode->value;
		pToDelete->next = pNode->next;
		delete pNode;
		pNode = NULL;
	}
	//������ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
	else if (*pListHead == pToDelete)
	{
		delete pToDelete;
		pToDelete = NULL;
		pListHead = NULL;
	}
	//�������ж����㣬Ҫɾ���Ľ����β������Ҫ�ҵ�ɾ������ǰһ�����(���淽��)
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
	printf("���뵥����Ľ��ֵ����-1������");
	H = createList();
	printf("����Ҫɾ���Ľ���ֵ��");
	scanf_s("%d",&x);
	q = find(H,x);
	DeleteNode(&H,q);
	p = H->next;
	printf("ɾ��һ�����%d���ֵΪ ��",x);
	while (p != NULL)
	{
		printf("%3d",p->value);
		p = p->next;
	}
	printf("\n");

	return 0;
}

/*
���뵥����Ľ��ֵ����-1������1 2 3 4 5 6 -1
����Ҫɾ���Ľ���ֵ��1
ɾ��һ�����1���ֵΪ ��  2  3  4  5  6
�밴���������. . .

���뵥����Ľ��ֵ����-1������1 2 3 4 5 6 -1
����Ҫɾ���Ľ���ֵ��3
ɾ��һ�����3���ֵΪ ��  1  2  4  5  6
�밴���������. . .

���뵥����Ľ��ֵ����-1������1 2 3 4 5 6 -1
����Ҫɾ���Ľ���ֵ��6
ɾ��һ�����6���ֵΪ ��  1  2  3  4  5
�밴���������. . .
*/