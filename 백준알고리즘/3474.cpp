// 교수가 된 현우
#include <iostream>
#pragma warning (disable:4996)
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int sum = 0;
		int n;
		cin >> n;
		for (int j = 5; j <= n; j *= 5)
		{
			sum += n / j;
		}
		cout << sum << "\n";
	}
	return 0;

}

