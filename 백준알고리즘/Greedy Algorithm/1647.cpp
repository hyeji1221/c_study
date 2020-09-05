#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000

int parent[MAX];
int n, m, total;
vector < pair<int, pair<int, int>>> v;
vector <int>v1;

int Find(int x)
{
	if (parent[x] == x) return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y) parent[y] = x; // 부모를 같게하여 연결
}

bool Sameparent(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; // 컴퓨터의 수, 연결할 수 있는 선의 수
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		if (Sameparent(v[i].second.first, v[i].second.second) == false) { // true인 경우는 순환이 일어나는 경우
			Union(v[i].second.first, v[i].second.second);
			v1.push_back(v[i].first);
		}
	}
	for (int i = 0; i < v1.size() - 1; i++) // 마지막에 연결된 가중치를 제외
		total += v1[i];
	cout << total << "\n";
}