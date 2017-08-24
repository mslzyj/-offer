#include<stdio.h>
//二进制中1的个数解法一:为了避免死循环，首先把n和1做与运算，判断n最低位是不是1，接着把1
//左移一位得到2，再和n做与运算，整数中有多少位，就需要循环多少次
//
int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
	
}
//解法二：把一个整数减去1再和原来的整数做与运算，就会把该整数的二进制表示形式中最右边的1变成0，那么，一个整数中有多少个1就需要循环多少次
int NumberOf2(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)& n;
	}
	return count;
}
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("解法一：该整数表示成二进制的形式中1 的个数为：%d\n", NumberOf1(n));
    printf("解法二：该整数表示成二进制的形式中1 的个数为：%d\n", NumberOf2(n));
	return 0;
}
/*
7
解法一：该整数表示成二进制的形式中1 的个数为：3
解法二：该整数表示成二进制的形式中1 的个数为：3
请按任意键继续. . .

*/