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
	printf("创建链表，输入整数，以-1结束：");
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
	//如果链表为空或k等于0，返回NULL
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
			return NULL;   //如果链表的长度小于K，返回NULL
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
	printf("创建的链表为：");
	while (p!=NULL)
	{
		printf("%3d",p->value);
		p = p->next;
	}
	printf("\n");
	printf("链表创建完成，输入要查找的倒数位置：");
	scanf_s("%d", &k);
	q = FindKToTail(H,k);
	if (q == NULL)
		printf("链表为空或k大于链表的长度\n");
	else
	    printf("倒数第 %d 个位置的值为 %d\n",k,q->value);

	return 0;
}

/*
创建链表，输入整数，以-1结束：1 2 3 4 5 6 7 8 9 10 -1
创建的链表为：  1  2  3  4  5  6  7  8  9 10
链表创建完成，输入要查找的倒数位置：5
倒数第 5 个位置的值为 6
请按任意键继续. . .

创建链表，输入整数，以-1结束：-1
创建的链表为：
链表创建完成，输入要查找的倒数位置：0
链表为空或k大于链表的长度
请按任意键继续. . .

创建链表，输入整数，以-1结束：1 2 3 -1
创建的链表为：  1  2  3
链表创建完成，输入要查找的倒数位置：5
链表为空或k大于链表的长度
请按任意键继续. . .


*/