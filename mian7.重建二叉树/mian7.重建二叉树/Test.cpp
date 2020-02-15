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
//	//ǰ��������еĵ�һ�������Ǹ��ڵ��ֵ
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
//	//����������������ҵ����ڵ��ֵ
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
//		//����������
//		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
//	}
//	if (leftLength < endPreorder - startPreorder)
//	{
//		//����������
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
		//�ж��ݹ���ֹ������
		if (pre.size() == 0 || vin.size() == 0) {
			return NULL;
		}
		//����Node�ڵ㲢������ڵ㣻
		int root = pre[0];
		TreeNode* node = new TreeNode(root);
		vector<int>::iterator it;
		//1.�����������ı������У�
		vector<int> preLeft, preRight, inLeft, inRight;
		//��1��.����ڵ���������������е�λ�ã�
		vector<int>::iterator i;
		for (it = vin.begin(); it != vin.end(); it++) {
			if (root == *it) {
				i = it;
			}
		}
		//��2��.������������������������У�
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
		//��3��.������������ǰ����������У�
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
		//���ݱ�����������������ҽڵ㣻
		node->left = reConstructBinaryTree(preLeft, inLeft);
		node->right = reConstructBinaryTree(preRight, inRight);
		//���ؽڵ��ַ��
		return node;
	}
};