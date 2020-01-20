#define _CRT_SECURE_NO_WARNINGS 1
int MinInOrder(vector<int> array,int left,int right)
{
	int result = array[left];
	for (int i = left + 1; i <= right; ++i)
	{
		if (result > array[i])
			result = array[i];
	}
	return result;
}
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = 0;
		while (rotateArray[left] >= rotateArray[right])
		{
			if (left + 1 == right)
			{
				mid = right;
				break;
			}
			mid = (left + right) >> 1;
			//如果下标为left right mid指向的三个数字相等，
			//则只能顺序查找
			if (rotateArray[left] == rotateArray[mid]
				&& rotateArray[mid] == rotateArray[right])
				return MinInOrder(rotateArray, left, right);
			if (rotateArray[mid] >= rotateArray[left])
				left = mid;
			else
				right = mid;
		}
		return rotateArray[mid];
	}
};