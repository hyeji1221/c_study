// 플로이드 - 와샬 알고리즘을 통하여 모든 정점에서 모든 정점까지 최소 경로를 구하는데 거쳐서 가는 경우가 바로 가는 경우보다 큰 경우에는 따로 처리해주고 
// 거쳐서 가는 경우와 바로 가는 경우가 같을 때에는  바로 가는 경우를 지워줌으로서 도로의 개수의 최솟값을 구하기

#include <iostream>
#define MAX 20
using namespace std;
int n, check;
int arr[MAX][MAX];
bool road[MAX][MAX] = { 1, };

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == k || j == k || i==j)
					continue;
				else if (arr[i][j] > arr[i][k] + arr[k][j]) { // 최소 경로가 성립하지 않는 경우 종료
					check = -1;
					return;
				}
				else if (arr[i][j] == arr[i][k] + arr[k][j]) // 바로 가는 경로 없애주기
					road[i][j] = false;
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			road[i][j] = true;
		}
	}

	floyd();

	if (check == -1)
		cout << -1 << "\n";

	else {
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (road[i][j])
					total += arr[i][j];
			}
		} // road[i][j]와 road [j][i]모두 계산하였으므로 2 나누기
		cout << total / 2 << "\n";
	}
		
	return 0;
}