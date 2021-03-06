#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool scanUnsignedInteger(char** str)
	{
		char* before = *str;
		while (**str != '\0' && **str >= '0' && **str <= '9')
			++(*str);
		//当str中存在若干0-9的数字时，返回true
		return *str > before;
	}
	bool scanInteger(char** str)
	{
		if (**str == '+' || **str == '-')
			++(*str);
		return scanUnsignedInteger(str);
	}
	bool isNumeric(char* str)
	{
		if (str == nullptr)
			return false;
		bool numeric = scanInteger(&str);

		//如果出现'.',则接下来是数字的小数部分
		if (*str == '.')
		{
			++str;

			//1.小数可以没有整数部分，如.123等于0.123
			//2.小数点后面可以没有数字，如233.等于233.0
			//3.当然，小数点前面和后面可以有数字，如233.666
			numeric = scanUnsignedInteger(&str) || numeric;
		}
		//如果出现‘e’或者'E',则接下来是数字的指数部分
		if (*str == 'e' || *str == 'E')
		{
			++str;

			//下面一行代码用&&的原因
			//1.当e或E前面没有数字时，整个字符串不能表示数字，如.e1、e1
			//2.当e或E后面没有整数时，整个字符串不能表示数字，如12e、12e+5.4
			numeric = numeric && scanInteger(&str);
		}

		return numeric && *str == '\0';
	}

};