#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int Fibonacci(int n) {
		int result[2] = { 0,1 };
		if (n < 2)
			return result[n];
		long long fibNMinusOne = 1;
		long long fibNMinusTwo = 0;
		long long fibN = 0;
		for (unsigned int i = 2; i <= n; ++i)
		{
			fibN = fibNMinusOne + fibNMinusTwo;

			fibNMinusTwo = fibNMinusOne;
			fibNMinusOne = fibN;
		}

		return fibN;

	}
};