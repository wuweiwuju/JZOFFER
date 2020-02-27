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
		//���뵱ǰ���ڵ�
		path.push_back(root->val);
		//ȷ����Ҷ�ӽڵ㲢����sumҪ��ȣ������뵽��ά����res��
		if (!root->left && !root->right && root->val == sum)
			res.push_back(path);
		else
		{
			//��������Ϊ�ռ����ݹ����
			if (root->left)
				Find(root->left, sum - root->val);
			//��������Ϊ�ռ����ݹ����
			if (root->right)
				Find(root->right, sum - root->val);
		}
		//ɾ��Ҷ�ӽڵ�
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