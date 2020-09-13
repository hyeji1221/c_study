#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000] = { 0, };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, t;
	int k, s;
	cin >> n >> t; // 단원 개수, 시험까지 공부할 수 있는 시간
	for (int i = 0; i < n; i++) {
		cin >> k >> s; // 단원 별 예상 공부 시간, 그 단원 문제의 배점
		for (int j = t; j >= k; j--) {
			arr[j] = max(arr[j], arr[j - k] + s); // arr[j - k]는 사용할 공부 시간
		}
	}
	cout << arr[t] << "\n";
	
	
	return 0;
}
