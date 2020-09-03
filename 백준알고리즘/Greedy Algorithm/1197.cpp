// 최소 신장트리로 구현하고 크루스칼 알고리즘을 이용한다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
int V, E; //V는 정점의 수, E는 간선의 수
vector<pair<int, pair<int, int>>> v; // 정점, 정점, 가중치
int parent[MAX];
int total = 0;

int Find(int x) // 부모 찾기
{
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y) // 서로 사이클이 일어나지 않는 경우이면
		parent[y] = x; // x와 y의 부모를 갖게한다.
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
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end()); // 가중치를 기준으로 정렬

	for (int i = 1; i <= V; i++) {
		parent[i] = i; // 부모를 각  자신으로 초기화
	}
	for (int i = 0; i < E; i++) {
		if (Sameparent(v[i].second.first, v[i].second.second) == false) {
			Union(v[i].second.first, v[i].second.second);
			total += v[i].first; // first는 가중치
		}
	}
	cout << total << "\n";
}
