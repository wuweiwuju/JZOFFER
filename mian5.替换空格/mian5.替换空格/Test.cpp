#define _CRT_SECURE_NO_WARNINGS 1
void ReleaceBlack(char string[], int length)
{
	if (string == nullptr || length <= 0)
		return;
	//originalLength为字符串string的实际长度
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++originalLength;

		if (string[i] == ' ')
			++numberOfBlank;

		++i;
	}
	//newLength为把空格替换成%20之后的长度
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}

		--indexOfOriginal;
	}
}