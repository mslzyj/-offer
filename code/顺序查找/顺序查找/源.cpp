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
	int length;  //���г��ȣ���ʵ�ʼ�¼����
}SeqList;

/*
  ���㷨��ʱ�������Ҫ������whileѭ����
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
  ���������0��λ����Ϊ�����ڣ���¼����Ĺؼ��֣�ƽ�����ҳ���Ϊ ��n+1��/2,
  �������ʧ�ܣ�  ��n+1��/2 <ƽ�����Ҵ���<(n+1)
*/
int SeqSearch2(SeqList L, KeyType k)
{
	L.r[0].key = k;    //������
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
	printf("���ҵ�λ��Ϊ��%d\n",i);
	i = SeqSearch2(L, i);
	printf("�������ڲ��ң�%d\n", i);
	return 0;
}
/*
1  2  3  4  5  6  7  8  9
���ҵ�λ��Ϊ��5
�������ڲ��ң�5
�밴���������. . .
*/