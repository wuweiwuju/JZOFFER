//1.0��n-1��ȱʧ������
class Solution {
public:
	int getMissingNumber(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i <= nums.size(); ++i)
			sum += i;
		for (int i = 0; i < nums.size(); ++i)
			sum -= nums[i];

		return sum;
	}
};
//2.��������ֵ���±���ȵ�Ԫ��
class Solution {
public:
	int getNumberSameAsIndex(vector<int>& nums) {
		int l = 0, r = nums.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (mid == nums[mid])    return mid;

			if (mid < nums[mid]) r = mid;
			else l = mid + 1;
		}
		return -1;
	}
};
//3.�����������ĵ�k�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* res;
	void dfs(TreeNode* root, int& k) {
		if (!root) return;
		dfs(root->left, k);
		k--;
		if (k == 0)  res = root;
		else dfs(root->right, k);
	}
	TreeNode* kthNode(TreeNode* root, int k) {
		dfs(root, k);
		return res;
	}
};
//4.�����������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int treeDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return max(treeDepth(root->left), treeDepth(root->right)) + 1;
	}
};
//5.ƽ�������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool ans = true;
	bool isBalanced(TreeNode* root) {
		dfs(root);
		return ans;
	}
	int dfs(TreeNode* root)
	{
		if (!root)   return 0;
		if (abs(dfs(root->left) - dfs(root->right) + 1) > 1)    ans = false;

		return 1;
	}
};
//6.������ֻ����һ�ε���������
class Solution {
public:
	vector<int> findNumsAppearOnce(vector<int>& nums) {
		int num = 0, k = 0;
		for (int i = 0; i < nums.size(); ++i)
			num ^= nums[i];

		for (int i = 0; i < 32; ++i)
			if (((num >> i) & 1) == 1) {
				k = i;
				break;
			}

		int num1 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (((nums[i] >> k) & 1) == 1) {
				num1 ^= nums[i];
			}
		}

		return vector<int>{num1, num^num1};
	}
};
//7.������Ψһֻ����һ�ε�����
class Solution {
public:
	int findNumberAppearingOnce(vector<int>& nums) {
		int count[32] = { 0 };
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < 32; ++j) {
				if (((nums[i] >> j) & 1) == 1)
					count[j]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < 32; ++i) {
			if (count[i] % 3 == 1)
				ans += (1 << i);
		}
		return ans;
	}
};
//8.��ΪS����������
class Solution {
public:
	vector<int> findNumbersWithSum(vector<int>& nums, int target) {
		unordered_set<int> hash;
		for (int i = 0; i < nums.size(); ++i)
		{
			//�ж�֮ǰ�ǲ��Ǵ��ڹ�
			if (hash.count(target - nums[i]))
				return vector<int>{nums[i], target - nums[i]};

			//��ÿһ���������ϣ����
			hash.insert(nums[i]);
		}
	}
};
//9.��ΪS��������������
class Solution {
public:
	vector<vector<int> > findContinuousSequence(int sum) {
		vector<vector<int>> res;
		vector<int> line;

		for (int i = 1, j = 1, s = 1; i <= sum / 2 + 1; ++i)
		{
			while (s < sum) s += ++j;
			if (sum == s && j > i)
			{
				for (int k = i; k <= j; ++k)
					line.push_back(k);

				res.push_back(line);
				line.clear();
			}
			s -= i;
		}

		return res;
	}
};
//10.��ת����˳��
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i)
		{
			int k = i;
			while (k < s.size() && s[k] != ' ')  ++k;
			reverse(s.begin() + i, s.begin() + k);
			i = k;
		}

		return s;

	}
};
//11.����ת�ַ���
class Solution {
public:
	string leftRotateString(string str, int n) {
		return str.substr(n) + str.substr(0, n);
	}
};