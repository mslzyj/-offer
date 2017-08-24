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
			// ������ջ��ջ��Ԫ�ز���Ҫ������Ԫ��
			// ��ѹ��һЩ������ջ
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				// ����������ֶ�ѹ�븨��ջ�ˣ��˳�ѭ��
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)//���ջ��Ԫ�ز���Ҫ������Ԫ��
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
		printf("��\n");
	else
		printf("����\n");
	return 0;
}