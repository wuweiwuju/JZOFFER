class Solution
{
public:
	void push(int node) {
		stack2.push(node);
	}

	int pop() {
		int temp = stack2.size();
		if (stack1.empty())
		{
			for (int i = 0; i < temp; i++)
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		int val = stack1.top();
		stack1.pop();
		return val;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};