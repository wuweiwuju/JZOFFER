class Solution {
	bool judge(vector<int>& a, int left, int right) {
		if (left >= right)
			return true;
		int i = left;
		for (; i < right; ++i)
		{
			if (a[i] > a[right])
				break;
		}
		for (int j = i; j < right; ++j)
		{
			if (a[j] < a[right])
				return false;
		}
		return judge(a, left, i - 1) && (judge(a, i, right - 1));
	}
public:
	bool VerifySquenceOfBST(vector<int> a) {
		if (a.size() == 0)
			return false;
		return judge(a, 0, a.size() - 1);
	}
};