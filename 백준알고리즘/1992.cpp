#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
int arr[65][65];

void check(int x, int y, int n)
{
	if (n == 1)
	{
		cout << arr[y][x];
		return;
	}

	int total = 0;
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (arr[i][j])
				total++;
		}
	}
	if (total == n * n)
		cout << 1;
	else if (!total)
		cout << 0;
	else
	{
		cout << "(";
		check(x, y, n / 2);
		check(x + n / 2, y, n / 2);
		check(x, y + n / 2, n / 2);
		check(x + n / 2, y + n / 2, n / 2);
		cout << ")";
	}
	return;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = n - 1; j >= 0; j--)
		{
			arr[i][j] = s[j] - '0';
		}

	}
	check(0, 0, n);
	cout << "\n";
	return 0;
}