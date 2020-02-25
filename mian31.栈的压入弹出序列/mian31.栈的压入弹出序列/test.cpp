#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
			return false;
		stack<int> array;
		int j = 0;
		for (int i = 0; i < popV.size(); ++i)
		{
			if (pushV[i] != popV[j])
				array.push(pushV[i]);
			else
				++j;
		}
		for (int i = j; i < popV.size(); ++i)
		{
			if (array.top() != popV[i])
				return false;
			else
				array.pop();
		}
		return true;
	}
};