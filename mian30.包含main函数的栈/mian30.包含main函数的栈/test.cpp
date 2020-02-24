#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	void push(int value) {
		if (arr1.empty())
		{
			arr1.push(value);
			arr2.push(value);
		}
		else
		{
			arr1.push(value);
			if (value <= arr2.top())
			{
				arr2.push(value);
			}
		}
	}
	void pop() {
		if (!arr1.empty())
		{
			if (arr1.top() == arr2.top())
			{
				arr1.pop();
				arr2.pop();
			}
			else
			{
				arr1.pop();
			}
		}
	}
	int top() {
		if (!arr1.empty())
			return arr1.top();
	}
	int min() {
		if (!arr1.empty())
			return arr2.top();
	}
private:
	stack<int> arr1;
	stack<int> arr2;
};