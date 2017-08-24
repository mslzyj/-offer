#include <stdio.h>
#include <string.h>
#include "malloc.h"
#define MAXSIZE 1000

typedef int KeyType;
typedef struct
{
	KeyType key;
}RecordType;

typedef struct 
{
	RecordType r[MAXSIZE+1];
	int length;  //序列长度，即实际记录个数
}SeqList;

/*
  该算法的时间代价主要消耗在while循环处
*/
int SeqSearch1(SeqList L,KeyType k)
{
	int i =L.length;
	while (i>=1 && L.r[i].key!= k)
	{
		i--;
	}
	if (i >= 1){
		return i;
	}
	else
		return 0;
}
/*
  算大利用了0号位置作为监视哨，记录待查的关键字，平均查找长度为 （n+1）/2,
  如果查找失败：  （n+1）/2 <平均查找次数<(n+1)
*/
int SeqSearch2(SeqList L, KeyType k)
{
	L.r[0].key = k;    //监视哨
	int i = L.length;
	while ( L.r[i].key != k)
		i--;
		return i;
}
int main()
{
	int i=900;
	SeqList L ;
	for (int i = 1; i < MAXSIZE; i++){
		L.r[i].key = i ;
		printf("%3d", L.r[i].key);
	}
	printf("\n");
	L.length =MAXSIZE;
	i = SeqSearch1(L,i);
	printf("查找的位置为：%d\n",i);
	i = SeqSearch2(L, i);
	printf("带监视哨查找：%d\n", i);
	return 0;
}
/*
1  2  3  4  5  6  7  8  9
查找的位置为：5
带监视哨查找：5
请按任意键继续. . .
*/