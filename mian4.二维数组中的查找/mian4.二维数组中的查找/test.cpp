#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array[0].size() - 1;
		int col = 0;
		while (col >= 0 && row >= 0 && col < array.size())
		{
			if (array[col][row] == target)
				return true;
			else if (array[col][row] > target)
				row--;
			else
				col++;
		}
		return false;
	}
};