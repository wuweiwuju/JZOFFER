//1.找出数组中重复的数字
class Solution {
public:
	int duplicateInArray(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return -1;
		int n = nums.size();
		for (auto item : nums)
			if (item < 0 || item > n - 1)
				return -1;

		for (int i = 0; i < n; ++i)
		{
			while (nums[i] != i && nums[nums[i]] != nums[i])
				swap(nums[i], nums[nums[i]]);
			if (nums[nums[i]] == nums[i] && nums[i] != i)
				return nums[i];
		}

		return -1;
	}
};
//2.不修改数组找出重复的数字
class Solution {
public:
	int duplicateInArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 2)  return nums[0];

		int l = 1, r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1; // [l,mid] [mid+1,r]
			int sum = 0;
			for (auto m : nums)
			{
				if (m >= l && m <= mid)
					++sum;
			}
			if (sum > mid - l + 1)   r = mid;
			else    l = mid + 1;

		}
		return r;
	}
};
//3.二维数组中的查找
class Solution {
public:
	bool searchArray(vector<vector<int>> array, int target) {
		if (array.size() == 0)
			return false;
		int left = 0, right = array[0].size() - 1;
		int up = 0, down = array.size() - 1;
		while (left <= right && up <= down)
		{
			if (array[up][right] == target)
				return true;
			else if (array[up][right] > target)
				--right;
			else
				++up;
		}

		return false;
	}
};
//4.替换空格
class Solution {
public:
	string replaceSpaces(string &str) {
		if (str == " ")
			return str;
		int count = 0;
		for (auto& m : str)
			if (m == ' ') ++count;

		int n = str.size();
		str.resize(str.size() + 2 * count);

		for (int i = n - 1; i >= 0; --i)
		{
			if (str[i] != ' ')
				str[i + count * 2] = str[i];
			else
			{
				str[i + count * 2] = '0';
				str[i + count * 2 - 1] = '2';
				str[i + count * 2 - 2] = '%';
				--count;
			}

		}

		return str;
	}
};
//从尾到头打印链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> printListReversingly(ListNode* head) {
		vector<int> array;
		while (head) {
			array.push_back(head->val);
			head = head->next;
		}
		reverse(array.begin(), array.end());
		return array;
	}
};