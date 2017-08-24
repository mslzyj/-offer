#include<stdio.h>
#include"malloc.h"
typedef struct node
{
	int value;
	struct  node *next;
}*ListNode;

ListNode createList()
{
	ListNode H = (ListNode)malloc(sizeof(ListNode));
	H->next = NULL;
	ListNode r, s;
	r = H;
	int x;
	printf("��������������������-1������");
	scanf_s("%d",&x);
	while (x != -1)
	{
		s = (ListNode)malloc(sizeof(ListNode));
		s->value = x;
		s->next = r->next;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	return H;
}

ListNode FindKToTail(ListNode H, unsigned int k)
{
	//�������Ϊ�ջ�k����0������NULL
	if (H->next == NULL || k == 0)
		return NULL;
	ListNode  pBegin=H->next;
	ListNode  pEnd=NULL;
	for (unsigned int i = 0; i < k - 1;i++)
	{
		if (pBegin->next != NULL)
			pBegin = pBegin->next;
		else
		{
			return NULL;   //�������ĳ���С��K������NULL
		}
	}
	pEnd = H->next;
	while (pBegin->next !=NULL)
	{
		pBegin = pBegin->next;
		pEnd = pEnd->next;
	}
	return pEnd;
}
int main()
{
	ListNode H,p,q;
	unsigned int k = 0;
	H = createList();
	p = H->next;
	printf("����������Ϊ��");
	while (p!=NULL)
	{
		printf("%3d",p->value);
		p = p->next;
	}
	printf("\n");
	printf("��������ɣ�����Ҫ���ҵĵ���λ�ã�");
	scanf_s("%d", &k);
	q = FindKToTail(H,k);
	if (q == NULL)
		printf("����Ϊ�ջ�k��������ĳ���\n");
	else
	    printf("������ %d ��λ�õ�ֵΪ %d\n",k,q->value);

	return 0;
}

/*
��������������������-1������1 2 3 4 5 6 7 8 9 10 -1
����������Ϊ��  1  2  3  4  5  6  7  8  9 10
��������ɣ�����Ҫ���ҵĵ���λ�ã�5
������ 5 ��λ�õ�ֵΪ 6
�밴���������. . .

��������������������-1������-1
����������Ϊ��
��������ɣ�����Ҫ���ҵĵ���λ�ã�0
����Ϊ�ջ�k��������ĳ���
�밴���������. . .

��������������������-1������1 2 3 -1
����������Ϊ��  1  2  3
��������ɣ�����Ҫ���ҵĵ���λ�ã�5
����Ϊ�ջ�k��������ĳ���
�밴���������. . .


*/