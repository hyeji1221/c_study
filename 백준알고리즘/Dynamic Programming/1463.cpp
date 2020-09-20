#include <iostream>
#include <algorithm>
using namespace std;
int dp[10000001];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; 
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[n] << "\n";
	return 0;
}
