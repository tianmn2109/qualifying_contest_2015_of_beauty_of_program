#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

bool isHui(string &s)
{
	if (s == "")
		return true;
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i ++;
		j --;
	}
	return true;
}

void cal(string s, string str, int len, long long &count)
{
	if (len == 0)
	{
		if (isHui(s))
			count ++;
		return ;
	}
	if (str.size() < len)
		return ;
	for (int i = 0; i < str.size() - len + 1; i ++)
	{
		int totallen = s.size() + len;
		if (s.size() >= len)
			if (s[len - 1] != str[i])
				continue;
		s.push_back(str[i]);
		cal(s, str.substr(i + 1), len - 1, count);
		//s.pop_back();
		s = s.substr(0, s.size() - 1);
	}
}

int main()
{
	int num;
	cin >> num;
	string str;
	string s;
	char ss[1001];
	long long count = 0;
	int id = 1;
	while (num --) {
		scanf("%s", ss);
		str = ss;
		count = 0;
		s = "";
		for (int len = 1; len <= str.size(); len ++)
			cal(s, str, len, count);
		printf("Case #%d: %lld\n", id ++, count % 100007);
	}
	return 0;
}
