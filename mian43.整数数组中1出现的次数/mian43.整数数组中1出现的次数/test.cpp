class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		int tab = 0;
		for (int i = 1; i <= n; ++i)
		{
			int temp = i;
			while (i)
			{
				tab = i % 10;
				if (tab == 1)
					count++;

				i /= 10;
			}
			i = temp;
		}
		return count;
	}
};