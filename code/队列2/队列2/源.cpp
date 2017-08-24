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
//����һ����ͷ���Ŀն�
LQueue Init_LQueue()
{
	LQueue q;
	Queue *p;
	q = (LQueue)malloc(sizeof(LQueue));//����ͷβָ����
	p = (Queue *)malloc(sizeof(Queue)); //��������ͷ���
	p->next = NULL;
	q->front = q->rear = p;
	return q;
}
//���
void InLQueue(LQueue q,int x)
{
	Queue *p;
	p = (Queue *)malloc(sizeof(Queue));//�����½��
	p->data = x;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}
//����
int out_Queue(LQueue q)
{
	int x;
	Queue *p;
	if (q->front == q->rear)
	{
		printf("�ӿ�\n");
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
//�жӿ�
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