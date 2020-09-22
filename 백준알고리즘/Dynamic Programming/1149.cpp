#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[3][1000];
int cost[3][1000];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; // 집의 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[0][i] >> cost[1][i] >> cost[2][i]; //각각 rgb
	}
	dp[0][0] = cost[0][0];
	dp[1][0] = cost[1][0];
	dp[2][0] = cost[2][0];
	for (int i = 1; i < N; i++) {
		dp[0][i] = min({ dp[1][i - 1], dp[2][i - 1] }) + cost[0][i];
		dp[1][i] = min({dp[0][i - 1], dp[2][i - 1]}) + cost[1][i];
		dp[2][i] = min({ dp[1][i - 1], dp[0][i - 1] }) + cost[2][i];
	}
	cout << min({dp[0][N - 1], dp[1][N - 1], dp[2][N - 1]});
	return 0;
}
