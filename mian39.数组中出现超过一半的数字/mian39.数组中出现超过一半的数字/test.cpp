#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		sort(numbers.begin(), numbers.end());
		int mid = numbers.size() / 2;
		int count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == numbers[mid])
				++count;
		}
		return count > mid ? numbers[mid] : 0;
	}
};