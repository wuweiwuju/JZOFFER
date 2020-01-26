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
		//���û�н�����ֻ��һ����㷵��pHead
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		//��ʱ���������������
		ListNode* n0 = NULL;
		ListNode* n1 = pHead;
		ListNode* n2 = pHead->next;
		ListNode* next = NULL;
		while (n2)
		{
			//�ж������ȵĻ���ͳһ�����ƶ�һ��
			if (n1->val != n2->val)
			{
				n0 = n1;
				n1 = n2;
				n2 = n2->next;
			}
			//������
			else
			{
				//�ҵ���n1����ȵĽ��
				while (n2 && n1->val == n2->val)
				{
					n2 = n2->next;
				}
				//���n0����NULL�Ļ���˵��ͷ���Ҫ��
				if (n0 == NULL)
				{
					pHead = n2;
				}
				//���n0��Ϊ��˵��ͷ�ڵ�û���ظ��ģ���ôn0->nextָ��Ҫָ��n2
				else
				{
					n0->next = n2;
				}
				//ɾ���ظ��Ľ��
				while (n1 != n2)
				{
					next = n1->next;
					free(n1);
					n1 = next;
				}
				//n2����������
				if (n2 != NULL)
				{
					n2 = n2->next;
				}
			}
		}
		return pHead;

	}
};
