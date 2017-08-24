#include <stdio.h>
#include "malloc.h"
typedef struct node
{
	int data;
	struct node *next;
}Queue;
typedef struct
{
	Queue *front;
	Queue *rear;
}* LQueue;
//创建一个带头结点的空队
LQueue Init_LQueue()
{
	LQueue q;
	Queue *p;
	q = (LQueue)malloc(sizeof(LQueue));//申请头尾指针结点
	p = (Queue *)malloc(sizeof(Queue)); //申请链队头结点
	p->next = NULL;
	q->front = q->rear = p;
	return q;
}
//入队
void InLQueue(LQueue q,int x)
{
	Queue *p;
	p = (Queue *)malloc(sizeof(Queue));//申请新结点
	p->data = x;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}
//出队
int out_Queue(LQueue q)
{
	int x;
	Queue *p;
	if (q->front == q->rear)
	{
		printf("队空\n");
		return false;
	}
	else
	{
		p = q->front->next;
		q->front->next = p->next;
		x = p->data;
		free(p);
		if (q->front->next == NULL)
			q->rear = q->front;
		return x;
	}

}
//判队空
int IsEmpty(LQueue q)
{
	if (q->front == q->rear)
		return 0;
	else
		return true;
}
int main()
{
	LQueue q = (LQueue)malloc(sizeof(LQueue));
	int x,result;
	q = Init_LQueue();
	scanf_s("%d",&x);
	while (x != -1){
		InLQueue(q, x);
		scanf_s("%d", &x);
	}
	result = out_Queue(q);
	printf("%d\n", result);
	return 0;
}