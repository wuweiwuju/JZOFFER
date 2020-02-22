#define _CRT_SECURE_NO_WARNINGS 1
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* Root1, TreeNode* Root2)
	{
		if (Root1 == nullptr && Root2 == nullptr)
			return true;

		if (Root1 == nullptr || Root2 == nullptr)
			return false;

		if (Root1->val != Root2->val)
			return false;
		return isSymmetrical(Root1->left, Root2->right) &&
			isSymmetrical(Root1->right, Root2->left);
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}

};