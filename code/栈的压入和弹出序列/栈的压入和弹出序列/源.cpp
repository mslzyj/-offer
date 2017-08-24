#include<stdio.h>
#include <stack>
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;

	if (pPush != nullptr && pPop != nullptr && nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;

		while (pNextPop - pPop < nLength)
		{
			// 当辅助栈的栈顶元素不是要弹出的元素
			// 先压入一些数字入栈
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				// 如果所有数字都压入辅助栈了，退出循环
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)//如果栈顶元素不是要弹出的元素
				break;

			stackData.pop(); 
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}

	return bPossible;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int b[5] = {4,5,3,1,2};
	if (IsPopOrder(a, b, 5))
		printf("是\n");
	else
		printf("不是\n");
	return 0;
}