#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		//如果没有结点或者只有一个结点返回pHead
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		//这时候至少有两个结点
		ListNode* n0 = NULL;
		ListNode* n1 = pHead;
		ListNode* n2 = pHead->next;
		ListNode* next = NULL;
		while (n2)
		{
			//判断如果相等的话，统一往后移动一下
			if (n1->val != n2->val)
			{
				n0 = n1;
				n1 = n2;
				n2 = n2->next;
			}
			//如果相等
			else
			{
				//找到与n1不相等的结点
				while (n2 && n1->val == n2->val)
				{
					n2 = n2->next;
				}
				//如果n0还是NULL的话，说明头结点要变
				if (n0 == NULL)
				{
					pHead = n2;
				}
				//如果n0不为空说明头节点没有重复的，那么n0->next指针要指向n2
				else
				{
					n0->next = n2;
				}
				//删除重复的结点
				while (n1 != n2)
				{
					next = n1->next;
					free(n1);
					n1 = next;
				}
				//n2继续往后走
				if (n2 != NULL)
				{
					n2 = n2->next;
				}
			}
		}
		return pHead;

	}
};
