#include <stdio.h>
#include <string.h>
#include "malloc.h"
#define MAXSIZE 20

typedef int KeyType;
typedef struct
{
	KeyType key;
}RecordType;

typedef struct
{
	RecordType r[MAXSIZE + 1];
	int length;  //���г��ȣ���ʵ�ʼ�¼����
}SeqList;

/*
���㷨��ʱ�������Ҫ������whileѭ����
*/
int SeqSearch1(SeqList L, KeyType k)
{
	int i = L.length;
	while (i >= 1 && L.r[i].key != k)
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
	while (L.r[i].key != k)
		i--;
	return i;
}

//�۰����(���ֲ���),ƽ�����ҳ���Ϊ (n+1)/n * (log 2) (n+1)-1
int BinSearch(SeqList L, KeyType k)
{
	int low = 1;
	int high = L.length;
	int mid;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (L.r[mid].key == k)
			return mid;
		else if (L.r[mid].key >= k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;

}
int main()
{
	int i = 0;
	SeqList L;
	for (int i = 1; i < MAXSIZE; i++){
		L.r[i].key = i;
		printf("%3d", L.r[i].key);
	}
	printf("\n");
	L.length = MAXSIZE;
	i = SeqSearch1(L, i);
	printf("���ҵ�λ��Ϊ��%d\n", i);
	i = SeqSearch2(L, i);
	printf("�������ڲ��ң�%d\n", i);
	printf("�۰���ң�%d\n", i);
	i = BinSearch(L, i);
	return 0;
}
/*
1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
���ҵ�λ��Ϊ��0
�������ڲ��ң�0
�۰���ң�0
�밴���������. . .
*/