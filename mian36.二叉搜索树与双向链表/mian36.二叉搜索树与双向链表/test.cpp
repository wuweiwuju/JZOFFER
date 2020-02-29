#define _CRT_SECURE_NO_WARNINGS 1
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	void ConvertNode(TreeNode* pNode, TreeNode*& pLastNode)
	{
		if (pNode == nullptr)
			return;

		TreeNode* pCur = pNode;

		if (pCur->left != nullptr)
			ConvertNode(pCur->left, pLastNode);

		pCur->left = pLastNode;
		if (pLastNode != nullptr)
			pLastNode->right = pCur;

		pLastNode = pCur;

		if (pCur->right != nullptr)
			ConvertNode(pCur->right, pLastNode);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pLastNode = nullptr;
		ConvertNode(pRootOfTree, pLastNode);

		//pLastNode指向双向链表的尾结点
		//我们要返回头结点
		TreeNode* pHeadNode = pLastNode;
		while (pHeadNode != nullptr && pHeadNode->left != nullptr)
			pHeadNode = pHeadNode->left;

		return pHeadNode;
	}
};