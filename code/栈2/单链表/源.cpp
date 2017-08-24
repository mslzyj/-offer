#include <stdio.h>
#include "malloc.h"

typedef struct Stacknode 
{
	int Data;
	struct  Stacknode *Next;
}slStacknode,*Stack;

void PushList(Stack S, int item){
	Stack  TmpCell;
	TmpCell = (Stack)malloc(sizeof(Stack));
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

int PopList(Stack S){
	Stack  FirstCell;
	int TopElem;
	if (S->Next == NULL){
		printf("栈空\n");
		return NULL;
	}
	else{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		TopElem = FirstCell->Data;
		free(FirstCell);
		return TopElem;
	}
}

void PrintList(Stack S) {
	Stack S1;
	S1 = S;
	S1 = S->Next;
	if (S1 == NULL) {
		printf("NULL\n");
		return;
	}
	while (S1 != NULL) {
		printf("%d ", S1->Data);
		S1 = S1->Next;
	}
	putchar('\n');
}
int main()
{
	Stack S;
	S = (Stack)malloc(sizeof(Stack));
	S->Next = NULL;
	PrintList(S);
	PushList(S, 1);
	PushList(S, 2);
	PushList(S, 3);
	PrintList(S);
	return 0;
}
