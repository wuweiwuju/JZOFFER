#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) {
	int Up = 0, Left = 0, Right = matrix[0].size(), Down = matrix.size();
	vector<int> array;
	if (Right == 0 || Down == 0)
		return array;
	--Right;
	--Down;
	while (Up <= Down && Left <= Right)
	{
		for (int i = Left; i <= Right; ++i)
		{
			array.push_back(matrix[Left][i]);
		}
		Up++;
		if (Up > Down)
			break;
		for (int i = Up; i <= Down; ++i)
		{
			array.push_back(matrix[i][Right]);
		}
		Right--;
		if (Left > Right)
			break;
		for (int i = Right; i >= Left; --i)
		{
			array.push_back(matrix[Down][i]);
		}
		Down--;
		for (int i = Down; i > Up - 1; --i)
		{
			array.push_back(matrix[i][Left]);
		}
		Left++;
	}
	return array;
}
int main()
{
	vector<vector<int> > matrix = { {1,2,3,4,5} };
	printMatrix(matrix);
}