#define _CRT_SECURE_NO_WARNINGS 1
bool g_InvalidInput = false;
double Power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unisgned int)(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
	{
		result *= base;
	}
	return result;
}

#include<math.h>
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return (double)1;
		if (base == 0)
			return (double)0;
		double sum = 1;
		int count = abs(exponent);
		while (count)
		{
			if (count & 1)
				sum *= base;
			base *= base;
			count >>= 1;
		}
		return exponent > 0 ? sum : 1 / sum;
	}
};
