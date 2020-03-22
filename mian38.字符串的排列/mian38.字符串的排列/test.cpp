#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<string> Permutation(string str)
	{
		vector<string> result;
		if (str.empty()) 
			return result;

		Permutation(str, result, 0);

		// ��ʱ�õ���result�����в������ֵ�˳�򣬿��Ե�����������
		sort(result.begin(), result.end());

		return result;
	}

	void Permutation(string str, vector<string> &result, int begin)
	{
		if (begin == str.size() - 1) // �ݹ���������������Ѿ�ָ��str���һ��Ԫ��ʱ
		{
			if (find(result.begin(), result.end(), str) == result.end())
			{
				// ���result�в�����str������ӣ�����aa��aa�ظ���ӵ����
				result.push_back(str);
			}
		}
		else
		{
			// ��һ��ѭ��i��begin��ȣ��൱�ڵ�һ��λ�����������ؼ�����֮���ѭ����
			// ֮��i != begin����ύ��������ͬλ���ϵ��ַ���ֱ��begin==str.size()-1�����������
			for (int i = begin; i < str.size(); ++i)
			{
				swap(str[i], str[begin]);
				Permutation(str, result, begin + 1);
				swap(str[i], str[begin]); // ��λ�����Իָ�֮ǰ�ַ���˳�򣬴ﵽ��һλ���θ�����λ������Ŀ��
			}
		}
	}

};