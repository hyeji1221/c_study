#include <iostream>
#include <queue>
#include <vector>
const int MAX =  32000 + 1;
using namespace std;
int n, m;
int degree[MAX]; // degree가 0이면 우선순위가 제일 높음
vector <int> a [MAX];
void Topology(void) // 위상정렬
{
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) //degree가 0이면
			q.push(i);
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		cout << n << " ";
		for (int i = 0; i < a[n].size(); i++) {
			int y = a[n][i];
			if (--degree[y] == 0) // 진입 차수가 0이면
				q.push(y);
		}
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int A, B;
		cin >> A >> B;
		a[A].push_back(B);
		degree[B]++; // 진입 차수 증가
	}
	Topology();
	return 0;
}