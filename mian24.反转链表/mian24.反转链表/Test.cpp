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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return pHead;
		ListNode* pre = pHead;
		ListNode* cur = pHead->next;
		ListNode* next = nullptr;
		pHead->next = nullptr;
		while (cur != nullptr)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		pHead = pre;
		return pHead;
	}
};