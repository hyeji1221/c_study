#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[1001][1001];
queue <int> q;
bool visit[1001];
int v, e, s;
void dfs(int n)
{
	cout << n<< " ";
	for (int i = 1; i <= v; i++)
		if (map[n][i] && !visit[i])
		{
			visit[i] = 1;
			dfs(i);
		}

}
void bfs(int n)
{
	q.push(n);
	visit[n] = 1;
	while (!q.empty())
	{
		n = q.front();
		q.pop();
		cout << n << " ";

		for (int i = 1; i <= v; i++) {
			if (map[n][i] && !visit[i]) {
				visit[i] = 1;
				q.push(i);
			
			}
		}
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> v >> e >> s;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	visit[s] = true;
	dfs(s);
	cout << "\n";
	memset(visit, 0, sizeof(visit));//visit 다시 0으로 초기화
	bfs(s);
	return 0;
}