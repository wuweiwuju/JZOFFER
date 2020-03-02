#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;
		int max = array[0];
		int sum = array[0];
		for (int i = 1; i < array.size(); ++i)
		{
			sum += array[i];
			if (sum < array[i])
				sum = array[i];

			if (sum > max)
				max = sum;
		}
		return max;
	}
};