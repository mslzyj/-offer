#include <cstdio>
#include<stdlib.h>
struct ListNode
{
	int       m_nValue;
	ListNode* m_pNext;
};
//尾插法创建链表
ListNode* CreateListNode(int data[],int length)
{
	ListNode *H = (ListNode *)malloc(sizeof(ListNode));
	H->m_pNext = NULL;
	ListNode *s, *r = H;
	for (int i = 0; i < length; i++)
	{
		s = (ListNode *)malloc(sizeof(ListNode));
		s->m_nValue = data[i];
		s->m_pNext = r->m_pNext;
		r->m_pNext = s;
		r = s;
	}
	return H;
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}
//删除链表中重复的结点
void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;  //当前结点的前一个结点
	ListNode* pNode = *pHead;     //当前结点
	while (pNode != nullptr)     
	{
		ListNode *pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)  //两个结点重复
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else              //删除
		{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}

			if (pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}


int main(int argc, char* argv[])
{
	int length = 8;
	ListNode* pHead = NULL,*p;
	int expectedValues[] = { 1, 2, 3,3,4,4,4,5 };
	pHead = CreateListNode(expectedValues, length);
	DeleteDuplication(&pHead);
	p = pHead->m_pNext;
	while (p != NULL)
	{
		printf("%3d", p->m_nValue);
		p = p->m_pNext;
	}
	printf("\n");
	DestroyList(pHead);
	return 0;
}