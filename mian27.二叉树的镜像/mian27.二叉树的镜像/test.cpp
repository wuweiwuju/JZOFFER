#define _CRT_SECURE_NO_WARNINGS 1
*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; */
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		if (pRoot->left == nullptr && pRoot->right == nullptr)
			return;

		swap(pRoot->left, pRoot->right);

		if (pRoot->left)
			Mirror(pRoot->left);

		if (pRoot->right)
			Mirror(pRoot->right);
	}
};