/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;
		TreeLinkNode* pNext = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode* pRight = pNode->right;

			while (pRight->left != nullptr)
				pRight = pRight->left;

			pNext = pRight;
		}
		else if (pNode->next != nullptr)
		{
			TreeLinkNode* pCurrent = pNode;
			TreeLinkNode* pParent = pNode->next;

			while (pParent != nullptr && pCurrent == pParent->right)
			{
				pCurrent = pParent;
				pParent = pParent->next;
			}

			pNext = pParent;
		}
		return pNext;
	}
};