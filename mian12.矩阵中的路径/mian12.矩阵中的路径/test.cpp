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
		//����ά��������Ԫ�س�ʼ��Ϊ0
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
	  ��Һã�����yishuihan�������Ŀ�ǻ��ݷ��ĵ�����Ŀ��
	  ���а˻ʺ�����Ҳ�Ǿ���Ļ��ݷ����⣬��ҿ��Բο�;�ڡ���ָoffer������Ҳ�����˰˻ʺ������˼·��
	  �������Ǹ�����ȫ�����������������ġ���ʵ���ݷ�Ҳ��ȫ���е�һ�ַ������ڱ����У�Ҳ���ǳ�����
	  matrix���������е���Ϊ���ķ�����Ȼ�����������������ĸ�����ĵݹ飻
	  �ڵݹ��У���������Ŀ�Ļ��Զ���ջ�ص���һ��״̬��
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
	/*����˵��*/
	bool haha(char* matrix, int rows, int cols, int i, int j, char* str, int k, bool* flag)
	{
		//��Ϊ��һά�����Ŷ�ά��ֵ��indexֵ�����൱�ڶ�ά����ģ�i��j����һά������±�
		int index = i * cols + j;
		//flag[index]==true,˵�������ʹ��ˣ���ôҲ����true;
		if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true)
			return false;
		//�ַ����Ѿ����ҽ�����˵���ҵ���·����
		if (str[k + 1] == '\0') return true;
		//���ĸ�������еݹ����,�������ң����ϣ����²���
		flag[index] = true;//��Ƿ��ʹ�
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