#include <iostream>
#include <climits>
using namespace std;
int arr[11][11];
int visit[11];
int n;
int m = INT_MAX;
// cnt는 방문한 도시의 수, y는 현재 노드 위치
void dfs(int start, int y, int sum, int cnt)
{
	if (cnt == n && y == start) { //순환했으면
		if (m > sum)
			m = sum; 
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!arr[y][i]) continue;
		// 노드 y에 방문하지 않았고 연결이 되어 있으면
		if (!visit[y] && arr[y][i] > 0) {
			visit[y] = true;
			sum += arr [y][i];
			if (sum <= m) { // 안넣으면 시간이 오래걸림
				dfs(start, i, sum, cnt + 1);
			}
			visit[y] = false; 
			// 방문한 노드가 가장 적은 노드의 길이 아니면 방문하지 않은 것으로 체크
			sum -= arr[y][i]; //sum 원상복구
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
		}
	}
	for (int i = 0; i < n; i++) { // 모든 정점에서 시작
		dfs(i, i, 0, 0);
	}
	cout << m;
}