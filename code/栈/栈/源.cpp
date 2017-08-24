#include <stdio.h>
#include <stdlib.h>
//定义栈
typedef struct node
{
	int data;
	struct node *next;
} *LinkSatck;


//入栈
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
		printf("内存已满\n");
	return top;

}
//出栈
int Pop(LinkSatck top)
{
	LinkSatck temp;
	int t;
	if (top->next == NULL)
		printf("栈空\n");
	else
	{
		temp = top->next;
		t = temp->data;
		top->next = temp->next;
		free(temp);
		
	}
	return t;
	
}
//打印
void print(LinkSatck top)
{
	if (top->next==NULL)
		printf("栈空\n");
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

//取栈顶元素
int SatckTop(LinkSatck top)
{
	if (top->next == NULL)
		printf("栈空\n");
	else
	    return top->next->data;
}
//求栈长
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
//初始化栈
void Stacks(LinkSatck top)
{
	top->next = NULL;
}

int main()
{
	LinkSatck top = (LinkSatck)malloc(sizeof(LinkSatck));    //注意    
	//入栈操作
	Stacks(top);
	Push(top, 1);    //入栈
	Push(top, 2);
	Push(top, 5);
	print(top);    //打印栈
	printf("%3d\n", SatckTop(top)); //取栈顶元素
	printf("%3d\n", StackLength(top)); //求栈长
	return 0;
}