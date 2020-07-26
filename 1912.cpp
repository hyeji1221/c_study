#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a[100000];
	int n;
	int m = -1001;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = max(a[i] + a[i - 1], a[i]);
		m = max(m, a[i]);
	}

	cout << m << "\n";
}