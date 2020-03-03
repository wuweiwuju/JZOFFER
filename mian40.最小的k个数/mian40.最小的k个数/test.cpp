#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.size() == 0 || k > input.size())
			return res;
		sort(input.begin(), input.end());
		for (int i = 0; i < k; ++i)
		{
			res.push_back(input[i]);
		}
		return res;
	}
};


//���ȼ�����Ĭ��������
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		priority_queue<int> arr;
		vector<int> res;
		if (k <= 0 || k > input.size())
			return res;
		for (int i = 0; i < input.size(); ++i)
		{
			if (arr.size() < k)
				arr.push(input[i]);
			else if (arr.top() > input[i])
			{
				arr.pop();
				arr.push(input[i]);
			}
		}

		for (int i = 0; i < k; ++i)
		{
			res.push_back(arr.top());
			arr.pop();
		}
		return res;
	}
};
class Solution {
public:
	void AdjustDown(vector<int>& a, int n, int root)
	{
		int parent = root;
		int child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n)
			{
				if (a[child + 1] > a[child])
					swap(a[child], a[child + 1]);
			}
			if (a[parent] < a[child])
			{
				swap(a[parent], a[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void HeapSort(vector<int>& a, int n)
	{
		//�����
		for (int i = (n - 2) / 2; i >= 0; --i)
		{
			AdjustDown(a, n, i);
		}
		//�������
		int end = n - 1;
		while (end > 0)
		{
			swap(a[0], a[end]);
			AdjustDown(a, end, 0);
			--end;
		}
	}
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (k <= 0 || k > input.size())
			return res;
		HeapSort(input, input.size());
		for (int i = 0; i < k; ++i)
		{
			res.push_back(input[i]);
		}
		return res;
	}
};
//��������ʵ��
class Solution {
public:
	int _QuickSort(vector<int>& a, int begin, int end)
	{
		int key = a[end];
		int keyindex = end;
		while (begin <= end)
		{
			//���ұ�Ϊ�����Ļ����͵ô���߿�ʼ���𣬷�ֹ������߱��ұߴ�����
			//������6 1 2 7 9��6Ϊ����
			while (begin < end && a[begin] <= key)
				++begin;
			while (begin < end && a[end] >= key)
				--end;

			if (begin >= end)
				break;

			swap(a[begin], a[end]);
		}
		//һ��Ҫע�����
		swap(a[begin], a[keyindex]);
		return begin;
	}
	void QuickSort(vector<int>& a, int left, int right)
	{
		if (left >= right)
			return;
		int keyindex = _QuickSort(a, left, right);
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
	void QuickSortNon(vector<int>& a, int begin, int end)
	{
		stack<int> p;
		p.push(begin);
		p.push(end);
		while (!p.empty())
		{
			int finish = p.top();
			p.pop();
			int start = p.top();
			p.pop();

			int keyindex = _QuickSort(a, start, finish);

			if (keyindex - 1 > start)
			{
				p.push(start);
				p.push(keyindex - 1);
			}

			if (keyindex + 1 < finish)
			{
				p.push(keyindex + 1);
				p.push(finish);
			}
		}
	}
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (k <= 0 || k > input.size())
			return res;
		//sort(input.begin(),input.end());
		//QuickSort(input, 0, input.size() - 1);
		QuickSortNon(input, 0, input.size() - 1);
		for (int i = 0; i < k; ++i)
		{
			res.push_back(input[i]);
		}
		return res;
	}
};