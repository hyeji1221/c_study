#include <iostream>
#include <map>
#include <cctype>
#include <cstdlib>


using namespace std;
string map1[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	map<string, int>map2;
	char str[21];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		map1[i] = a;
		map2.insert(pair<string, int>(a, i));
	}
	for (int i = 0; i < m; i++)
	{
		char str[100];
		cin >> str;
		string s = str;
		int num = atoi(str) - 1;
		if (isdigit(str[0])) //숫자이면
			cout << map1[num] << "\n";
		else {
			cout << map2[s] + 1 << "\n";
		}

	}


	return 0;

}