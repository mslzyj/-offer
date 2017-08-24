#include <stdio.h>
#include "malloc.h"
#define MAXSIZE 20
typedef struct
{
	int data[MAXSIZE];
	int front, rear;
}*CSeQueue;
//�öӿ�
CSeQueue InitSeQueue()
{
	CSeQueue q;
	q = (CSeQueue)malloc(sizeof(CSeQueue));
	q->front = q->rear = MAXSIZE - 1;
	return q;
}
//���
int InSeQueue(CSeQueue q, int x)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("����\n");
		return false;
	}
	else
	{
		
		q->rear = (q->rear + 1) % MAXSIZE;
		q->data[q->rear] = x;
		return true;
	}
}
//����
int OutSeQueue(CSeQueue q)
{
	int x=0;
	if (q->front == q->rear)
	{
		printf("�ӿ�\n");
		return false;
	}
	else
	{
		q->front = (q->front + 1)% MAXSIZE;
		x = q->data[q->front];
		return x;
	}
}
//�жӿ�
int IsEmpty(CSeQueue q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}
int main()
{
	CSeQueue q = (CSeQueue)malloc(sizeof(CSeQueue));
	int x, result;
	scanf_s("%d", &x);
	while (x != -1){
		InSeQueue(q, x);
		scanf_s("%d", &x);
	}
	result = OutSeQueue(q);
	printf("%d\n", result);
	return 0;
}