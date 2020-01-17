#define _CRT_SECURE_NO_WARNINGS 1
//ջʵ��
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
//�ݹ�ʵ��   ����̫���ʱ������ջ���
//����ջ����ѭ��ʵ�ֵĴ����³���Ը���
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