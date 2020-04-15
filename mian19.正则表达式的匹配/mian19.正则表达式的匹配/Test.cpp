#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;

		if (*str != '\0' && *pattern == '\0')
			return false;

		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
				return matchCore(str + 1, pattern + 2) ||
				matchCore(str + 1, pattern) ||
				matchCore(str, pattern + 2);
			else
				return matchCore(str, pattern + 2);
		}

		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);

		return false;
	}
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
			return false;

		return matchCore(str, pattern);
	}
};




/*
	��������Ҫ��������ϸ�о���������������˺ö�β����׵ġ�
	���ȣ��������������
		 1>�����ַ�����Ϊ�գ�����true
		 2>����һ���ַ������գ����ڶ����ַ������ˣ�����false����Ϊ���������޷�
			ƥ��ɹ���,�������һ���ַ������ˣ��ڶ����ַ����ǿգ����ǿ���ƥ���
			���ģ�����ڶ����ַ����ǡ�a*a*a*a*��,���ڡ�*��֮ǰ��Ԫ�ؿ��Գ���0�Σ�
			�����п���ƥ��ɹ���
	֮��Ϳ�ʼƥ���һ���ַ������������ֿ��ܣ�ƥ��ɹ���ƥ��ʧ�ܡ������ǵ�pattern
	��һ���ַ������ǡ�*���� �������Ƿ�����������ۣ�pattern��һ���ַ�Ϊ��*����
	��Ϊ��*����
		  1>pattern��һ���ַ���Ϊ��*������������Ƚϼ򵥣�ֱ��ƥ�䵱ǰ�ַ������
			ƥ��ɹ�������ƥ����һ�������ƥ��ʧ�ܣ�ֱ�ӷ���false��ע�������
			��ƥ��ɹ��������������ַ���ͬ������⣬����һ�����������pattern��
			��ǰ�ַ�Ϊ��.��,ͬʱstr�ĵ�ǰ�ַ���Ϊ��\0����
		  2>pattern��һ���ַ�Ϊ��*��ʱ����΢����һЩ����Ϊ��*�����Դ���0��������
			�������Щ��������ǵ���
			   a>����*��ƥ��0���ַ�ʱ��str��ǰ�ַ����䣬pattern��ǰ�ַ�������λ��
				���������*�����ţ�
			   b>����*��ƥ��1������ʱ��str��ǰ�ַ�������һ����pattern��ǰ�ַ�
				���䡣������ƥ��1���������Կ���һ���������Ϊ����ƥ��һ��ʱ��
				����str�Ƶ�����һ���ַ�����pattern�ַ����䣬�ͻص����ϱߵ����a��
				��ƥ�����һ���ַ�ʱ���൱�ڴ�str����һ���ַ�������ʼƥ�䣩
	֮����д����ͺܼ��ˡ�
*/
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		//if the next character in pattern is not '*'
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		//if the next character is '*'
		else
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str, pattern + 2) || match(str + 1, pattern);
			else
				return match(str, pattern + 2);
		}
	}
};