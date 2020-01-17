#define _CRT_SECURE_NO_WARNINGS 1
//栈实现
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}
//递归实现   数据太多的时候容易栈溢出
//即用栈基于循环实现的代码的鲁棒性更好
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
			PrintListReversingly_Iteratively(pHead->m_pNext);

		printf("%d\t", pHead->m_nValue);
	}
}


class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> ArrayList;
		stack<int> nodes;
		ListNode* pNode = head;
		while (pNode != nullptr)
		{
			nodes.push(pNode->val);
			pNode = pNode->next;
		}
		while (!nodes.empty())
		{
			ArrayList.push_back(nodes.top());
			nodes.pop();
		}
		return ArrayList;
	}
};