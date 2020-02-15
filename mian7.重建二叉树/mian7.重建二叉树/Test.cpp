//#define _CRT_SECURE_NO_WARNINGS 1
//BinaryTreeNode* Construt(int* preorder, int* inorder, int length)
//{
//	if (preorder == nullptr || inorder == nullptr || length <= 0)
//		return nullptr;
//
//	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
//}
//
//BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
//{
//	//前序遍历序列的第一个数字是根节点的值
//	int rootValue = startPreorder[0];
//	BinaryTreeNode* root = new BinaryTreeNode();
//	root->m_nValue = rootValue;
//	root->m_pLeft = root->m_pRight = nullptr;
//
//	if (startPreorder == endPreorder)
//	{
//		if (startInorder == endInorder && *startPreorder == *startInorder)
//			return root;
//		else
//			throw std::exception("Invalid input.");
//	}
//	//在中序遍历序列中找到根节点的值
//	int* rootInorder = startInorder;
//	while (rootInorder <= endInorder && *rootInorder != rootValue)
//		++rootInorder;
//
//	if(rootInorder == endInorder && *rootInorder != rootValue)
//		throw std::exception("Invalid input.");
//
//	int leftLength = rootInorder - startInorder;
//	int* leftPreorderEnd = startPreorder + leftLength;
//	if (leftLength > 0)
//	{
//		//构建左子树
//		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
//	}
//	if (leftLength < endPreorder - startPreorder)
//	{
//		//构建右子树
//		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
//	}
//	return root;
//}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//判定递归终止条件；
		if (pre.size() == 0 || vin.size() == 0) {
			return NULL;
		}
		//定义Node节点并其求根节点；
		int root = pre[0];
		TreeNode* node = new TreeNode(root);
		vector<int>::iterator it;
		//1.求左右子树的遍历序列；
		vector<int> preLeft, preRight, inLeft, inRight;
		//（1）.求根节点在中序遍历序列中的位置；
		vector<int>::iterator i;
		for (it = vin.begin(); it != vin.end(); it++) {
			if (root == *it) {
				i = it;
			}
		}
		//（2）.求左右子树的中序遍历子序列；
		int k = 0;
		for (it = vin.begin(); it != vin.end(); it++) {
			if (k == 0) {
				inLeft.push_back(*it);
			}
			else if (k == 1) {
				inRight.push_back(*it);
			}
			else {}
			if (it == i) {
				k = 1;
			}
		}
		//（3）.求左右子树的前序遍历子序列；
		k = 0;
		vector<int>::iterator ite;
		for (it = pre.begin() + 1; it != pre.end(); it++) {
			for (ite = inLeft.begin(); ite != inLeft.end(); ite++) {
				if (*it == *ite) {
					preLeft.push_back(*it);
					k = 1;
				}
			}
			if (k == 0) {
				preRight.push_back(*it);
			}
			k = 0;
		}
		//根据遍历序列求出跟的左右节点；
		node->left = reConstructBinaryTree(preLeft, inLeft);
		node->right = reConstructBinaryTree(preRight, inRight);
		//返回节点地址；
		return node;
	}
};