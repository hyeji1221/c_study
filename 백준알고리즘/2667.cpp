#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[25][25];
int total;
int n;
bool visit[25][25] = { 0, };
int dirx[4] = { 1,-1,0,0 };
int diry[4] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	total++;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dirx[i];
		int ny = y + diry[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == 1 && visit[nx][ny] == false)
			dfs(nx, ny);
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int>v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				total = 0;
				dfs(i, j);
				v.push_back(total);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

}