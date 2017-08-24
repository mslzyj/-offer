#include <stdio.h>
#include <stdlib.h>
//����ջ
typedef struct node
{
	int data;
	struct node *next;
} *LinkSatck;


//��ջ
LinkSatck Push(LinkSatck top,int x)
{
	LinkSatck newp = (LinkSatck)malloc(sizeof(LinkSatck));
	if (newp != NULL)
	{
		newp->data = x;
		newp->next = top->next;
		top->next = newp;
	}
	else
		printf("�ڴ�����\n");
	return top;

}
//��ջ
int Pop(LinkSatck top)
{
	LinkSatck temp;
	int t;
	if (top->next == NULL)
		printf("ջ��\n");
	else
	{
		temp = top->next;
		t = temp->data;
		top->next = temp->next;
		free(temp);
		
	}
	return t;
	
}
//��ӡ
void print(LinkSatck top)
{
	if (top->next==NULL)
		printf("ջ��\n");
	else
	{
		while (top->next != NULL)
		{
			printf("%3d", top->next->data);
			top=top->next ;
		}
		printf("\n");
	}

}

//ȡջ��Ԫ��
int SatckTop(LinkSatck top)
{
	if (top->next == NULL)
		printf("ջ��\n");
	else
	    return top->next->data;
}
//��ջ��
int StackLength(LinkSatck top)
{
	int len = 0;
	while (top->next != NULL)
	{
		len++;
		top = top->next;
	}

	return len;
}
//��ʼ��ջ
void Stacks(LinkSatck top)
{
	top->next = NULL;
}

int main()
{
	LinkSatck top = (LinkSatck)malloc(sizeof(LinkSatck));    //ע��    
	//��ջ����
	Stacks(top);
	Push(top, 1);    //��ջ
	Push(top, 2);
	Push(top, 5);
	print(top);    //��ӡջ
	printf("%3d\n", SatckTop(top)); //ȡջ��Ԫ��
	printf("%3d\n", StackLength(top)); //��ջ��
	return 0;
}