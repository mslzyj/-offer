/*
题目：构建乘积数组
     给定一个数组A[0,...,n-1],请构建一个数组B[0,.....,n-1],
	 其中，B中的元素B[i]=A[0]XA[1]X....A[i-1]XA[i+1]....XA[n-1]。不能使用除法。
*/

#include <cstdio>
void BuildProductionArray(double *input, double *output,int length)
{
	int length1 =length;
	int length2 = length;

	if (length1 == length2 && length2 > 1)
	{
		output[0] = 1;
		for (int i = 1; i < length1; ++i)
		{
			output[i] = output[i - 1] * input[i - 1];
		}

		double temp = 1;
		for (int i = length1 - 2; i >= 0; --i)
		{
			temp = input[i + 1];
			output[i] = temp;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		printf("%3d", output[i]);
	}
	printf("\n");
	
}
int main()
{
	double input[] = { 1, 2, 3, 4, 5 };
	double output[] = { 0, 0, 0, 0, 0 };
	BuildProductionArray(input, output,5);
	return 0;
}