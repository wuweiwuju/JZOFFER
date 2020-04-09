#define _CRT_SECURE_NO_WARNINGS 1
/*int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	bool *visited = new bool[rows*cols];
	for (int i = 0; i < rows*cols; ++i)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;

	return count;
}
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}

	return count;
}
bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= threshold
		&& !visited[row*cols + col])
		return true;

	return false;
}
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}*/


class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool* flag = new bool[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			flag[i] = false;
		int count = moving(threshold, rows, cols, 0, 0, flag);//从（0,0）坐标开始访问;
		delete[] flag;
		return count;
	}
	//计算最大移动位置
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		int count = 0;
		if (check(threshold, rows, cols, i, j, flag))
		{
			flag[i*cols + j] = true;
			//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
		   //因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
			count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
				+ moving(threshold, rows, cols, i, j - 1, flag)
				+ moving(threshold, rows, cols, i + 1, j, flag)
				+ moving(threshold, rows, cols, i, j + 1, flag);
		}
		return count;
	}
	//检查当前位置是否可以访问
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		if (i >= 0 && i < rows && j >= 0 && j < cols
			&& getSum(i) + getSum(j) <= threshold
			&& flag[i*cols + j] == false)
			return true;
		return false;
	}
	//计算位置的数值
	int getSum(int number)
	{
		int sum = 0;
		while (number > 0)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};