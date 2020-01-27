#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}
void PrintToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		PrintToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}
void PrintToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\n';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		PrintToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete[] number;
}

int main()
{
	PrintToMaxOfNDigits(2);
	return 0;
}