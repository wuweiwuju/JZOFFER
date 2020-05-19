/*#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
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
int main()
{
	int N;
	cin >> N;
	vector<int> res;

}*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int n;
	vector<int> res;
	queue<int> arr;
	while (cin >> n) {
		vector<string> str(n);
		getline(cin, str[0]);
		for (auto& e : str)
			getline(cin, e);

		for (int i = 0; i < n; ++i) {
			if (str[i] == "peek") {
				if (!arr.empty())
					res.push_back(arr.front());
			}
			else if (str[i] == "pool") {
				if (!arr.empty())
					arr.pop();
			}
			else {
				string temp = str[i];
				string tmp;
				int count = 0;
				for (int i = 0; i < temp.size(); ++i) {
					if (temp[i] >= '0' && temp[i] <= '9') {
						tmp += temp[i];
					}
				}
				arr.push(atoi(tmp.c_str()));
				tmp.clear();
			}
		}
		str.clear();

		for (auto& e : res)    cout << e << endl;
		res.clear();
	}

	return 0;
}