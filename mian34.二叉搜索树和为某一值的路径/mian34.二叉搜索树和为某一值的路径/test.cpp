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
	void Find(TreeNode*& root, int sum)
	{
		if (root == nullptr)
			return;
		//插入当前根节点
		path.push_back(root->val);
		//确保是叶子节点并且与sum要相等，即插入到二维数组res中
		if (!root->left && !root->right && root->val == sum)
			res.push_back(path);
		else
		{
			//左子树不为空继续递归求解
			if (root->left)
				Find(root->left, sum - root->val);
			//右子树不为空继续递归求解
			if (root->right)
				Find(root->right, sum - root->val);
		}
		//删除叶子节点
		path.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == nullptr)
			return res;
		Find(root, expectNumber);
		return res;
	}
private:
	vector<vector<int>> res;
	vector<int> path;
};