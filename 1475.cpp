#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	map<int, int>m;
	string s;
	cin >> s;
	int num=0;
	for (int i = 0; i < s.length(); i++)
	{
		int a = s[i] - '0';
		if (a == 9)
			m.insert(make_pair(6, m[a]++));
		else
			m.insert(make_pair(a, m[a]++));
	}
	for (int i = 0; i < 10; i++)
	{
		if (i != 9 && i != 6)
			num = max(num, m[i]);
	}
	cout << max(num, (m[6] + m[9] + 1) / 2);
}