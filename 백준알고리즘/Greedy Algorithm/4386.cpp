#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 1000000
int parent[MAX];
int n;
double total;
vector <pair<double, double>> v; // 처음에 입력받을 벡터
vector < pair<double, pair<int, int>>> v1; // 거리 계산후 이용할 벡터

double distance(double x1, double y1, double x2, double y2)
{
	double dx = (x1 - x2) * (x1 - x2);
	double dy = (y1 - y2) * (y1 - y2);
	double dist = sqrt(dx + dy);
	return dist;
}

int Find(int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = Find(parent[x]);
}

bool Sameparent(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < v.size(); i++) {
		double x1 = v[i].first;
		double y1 = v[i].second;
		for (int j = i + 1; j < v.size(); j++) {
			double x2 = v[j].first;
			double y2 = v[j].second;

			double dist = distance(x1, y1, x2, y2);
			v1.push_back(make_pair(dist, make_pair(i, j))); // 거리를 중심으로 벡터에 다시 넣기
		}
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) {
		double cost = v1[i].first;
		int node1 = v1[i].second.first;
		int node2 = v1[i].second.second;
		if (Sameparent(node1, node2) == false) {
			Union(node1, node2);
			total += cost;
		}
	}
	cout << fixed; // 소수점을 고정시켜 표현
	cout.precision(2); // 2자리까지 표현
	cout<< total << "\n";
}