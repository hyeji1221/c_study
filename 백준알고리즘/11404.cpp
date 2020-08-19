#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int n, m; //n은 도시 수, m은 버스의 수
int arr[100][100];
int INF = 999999999;
void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || arr[i][j] == INF) // 자기 자신에게 가는 경우는 0
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int start, finish, cost;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF; // 무한대로 초기화
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> finish >> cost;
		// 입력받을 때 start와 finish가 같은수가 또 입력받는 경우가 있기 때문
		if (arr[start - 1][finish - 1] > cost) 
			arr[start - 1][finish - 1] = cost;
	}
	floyd();
	return 0;
}