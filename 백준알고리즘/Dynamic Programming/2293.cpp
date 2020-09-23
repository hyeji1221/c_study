#include <iostream>
#include <algorithm>
/*첫 번째 동전만 사용하여 각 k값 마다 가능한 경우의 수를 찾는다.
첫 번째~두 번째 동전만 사용하였을 때, 각k 값 마다 가능한 경우의 수를 찾는다.이 때, 첫 번째 동전만 사용해서 구했던 경우의 수를 활용한다.
첫 번째~n 번째 동전을 사용하였을 때까지 반복한다.*/
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	int dp[10001] = { 0, };
	int coin[101] = { 0, };
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k ; j++) {
			dp[j] = dp[j] + dp[j - coin[i]]; // dp값이 변하는것 자체가 coin으로 가능하기 때문
		}
	}
	cout << dp[k] << "\n";
	return 0;
}
