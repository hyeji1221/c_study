#include <iostream>
#include <cstring> // memset
#include <vector>
#include <algorithm>
using namespace std;
int t, n; //t는 테스트 케이스, n은 편의점 수
vector <pair<int, int>>v;
int visit[100];
int nowx, nowy, storex, storey, rockx, rocky;
int check;

void dfs(int x, int y)
{
	int n;
	n = abs(rockx - x) + abs(rocky - y); // abs는 절대값

	if (n <= 1000) { //50m에 20개 이므로 총 갈수 있는 거리는 1000m
		check = 1;
		return;
	}
	for (int i = 0 ; i < v.size(); i++) {
		if (visit[i] == 1) {
			continue;
		}
		n = abs(v[i].first - x) + abs(v[i].second - y);
		if (n > 1000) // i번째 편의점에서 현재까지의 위치가 1000보다 크면 맥주 부족함
			continue;
		else {
			visit[i] = 1;
			dfs(v[i].first, v[i].second);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> nowx >> nowy;
		v.clear();
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) { // 편의점 위치 입력받기
			cin >> storex >> storey;
			v.push_back(make_pair(storex, storey));
		}
		cin >> rockx >> rocky;
		check = 0;
		dfs(nowx, nowy);
		if (check == 1)
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
	return 0;
	
}