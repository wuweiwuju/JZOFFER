#define _CRT_SECURE_NO_WARNINGS 1
//��̬�滮
class Solution {
public:
	int cutRope(int number) {
		if (number < 2)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;

		int *products = new int[number + 1];
		products[0] = 0;
		products[1] = 1;
		products[2] = 2;
		products[3] = 3;

		int max = 0;
		for (int i = 4; i <= number; ++i)
		{
			max = 0;
			for (int j = 1; j <= i / 2; ++j)
			{
				int product = products[j] * products[i - j];
				if (max < product)
					max = product;

				products[i] = max;
			}
		}

		max = products[number];
		delete[] products;

		return max;
	}
};
//̰���㷨
class Solution {
public:
	int cutRope(int number) {
		if (number < 2)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;

		//�����ܶ��ȥ������Ϊ3�����Ӷ�
		int timesOf3 = number / 3;

		//���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�ĵ����Ӷ�
		//��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2������ ��Ϊ2*2 > 3*1
		if (number - timesOf3 * 3 == 1)
			timesOf3 -= 1;

		int timesOf2 = (number - timesOf3 * 3) / 2;

		return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
	}
};