#define _CRT_SECURE_NO_WARNINGS 1
/*
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		//复制一个链表
		RandomListNode* pCur = pHead;
		while (pCur)
		{
			RandomListNode* pNode = new RandomListNode(pCur->label);
			pNode->next = pCur->next;
			pCur->next = pNode;
			pCur = pCur->next->next;
		}
		//复制随机指针的指向
		pCur = pHead;
		while (pCur)
		{
			if (pCur->random != nullptr)
				pCur->next->random = pCur->random->next;
			pCur = pCur->next->next;
		}
		//拆分链表
		RandomListNode* pNode = pHead->next;
		pCur = pHead;
		RandomListNode* pClone = pNode;
		while (pCur)
		{
			pCur->next = pNode->next;
			pCur = pCur->next;
			if (pCur)
				pNode->next = pCur->next;
			pNode = pNode->next;
		}
		return pClone;
	}
};