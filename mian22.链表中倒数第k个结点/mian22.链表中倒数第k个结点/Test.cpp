#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k == 0)
			return nullptr;
		ListNode* pNext = pListHead;
		ListNode* pCur = nullptr;
		for (int i = 0; i < k; ++i)
		{
			pCur = pNext;
			if (i < k && pCur == nullptr)
				return nullptr;
			pNext = pNext->next;
		}
		while (pCur->next)
		{
			pCur = pCur->next;
			pListHead = pListHead->next;
		}
		return pListHead;
	}
};