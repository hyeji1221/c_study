#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int arr[128][128];
int white, blue = 0;
void check(int x, int y, int n)
{
	int total = 0;
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (arr[i][j])
			{
				total++;
			}
		}
	}

	if (total == n * n)
		blue++;
	else if (!total)
		white++;
	else
	{
		check(x, y, n / 2);
		check(x + n/2, y, n / 2);
		check(x, y + n/2,n / 2);
		check(x + n/2, y + n/2, n / 2);
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	check(0, 0, n);
	cout << white << "\n";
	cout << blue << "\n";
	
}