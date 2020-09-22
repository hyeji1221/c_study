#include <iostream>
#include <algorithm>
using namespace std;
int dp[10000001];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}
	cout << dp[N]<<"\n";
	
	return 0;
}
