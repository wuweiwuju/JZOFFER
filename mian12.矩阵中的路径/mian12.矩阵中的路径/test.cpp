#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

/*class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
			return false;

		bool *visited = new bool[rows*cols];
		//将二维数组所有元素初始化为0
		memset(visited, 0, rows*cols);

		int pathLength = 0;
		for (int row = 0; row < rows; ++row)
		{
			for (int col = 0; col < cols; ++col)
			{
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
					return true;
			}
		}

		delete[] visited;
		return false;
	}
	bool hasPathCore(const char* matrix, int rows, int cols,
		int row, int col, const char* str,
		int pathLength, bool* visited)
	{
		if (str[pathLength] == '\0')
			return true;

		bool hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols
			&& matrix[row*cols + col] == str[pathLength]
			&& !visited[row*cols + col])
		{
			++pathLength;
			visited[row*cols + col] = true;

			hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
				str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row - 1, col,
					str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1,
					str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col,
					str, pathLength, visited);

			if (!hasPath)
			{
				--pathLength;
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}


};

*/

class Solution {
public:
	/*
	  大家好，我是yishuihan，这个题目是回溯法的典型题目；
	  还有八皇后问题也是经典的回溯法例题，大家可以参考;在《剑指offer》书中也给出了八皇后问题的思路；
	  不过，那个是在全排列问题中引出来的。其实回溯法也是全排列的一种方案，在本题中，也就是尝试了
	  matrix矩阵中所有点作为起点的方法，然后依据这个点进行向四个方向的递归；
	  在递归中，不满足题目的会自动出栈回到上一个状态；
	*/
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) return false;
		bool *flag = new bool[rows*cols];
		memset(flag, false, rows*cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (haha(matrix, rows, cols, i, j, str, 0, flag))
				{
					return true;
				}
			}
		}
		delete[] flag;
		return false;
	}
	/*参数说明*/
	bool haha(char* matrix, int rows, int cols, int i, int j, char* str, int k, bool* flag)
	{
		//因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
		int index = i * cols + j;
		//flag[index]==true,说明被访问过了，那么也返回true;
		if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true)
			return false;
		//字符串已经查找结束，说明找到该路径了
		if (str[k + 1] == '\0') return true;
		//向四个方向进行递归查找,向左，向右，向上，向下查找
		flag[index] = true;//标记访问过
		if (haha(matrix, rows, cols, i - 1, j, str, k + 1, flag)
			|| haha(matrix, rows, cols, i + 1, j, str, k + 1, flag)
			|| haha(matrix, rows, cols, i, j - 1, str, k + 1, flag)
			|| haha(matrix, rows, cols, i, j + 1, str, k + 1, flag))
		{
			return true;
		}
		flag[index] = false;
		return false;
	}
};