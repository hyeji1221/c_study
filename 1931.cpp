#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//second를 기준으로 정렬
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<pair<int, int>> v;
	int total = 0;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end(), compare);
	int s = v[0].first;
	int e = v[0].second;
	for (int i = 1; i <num; i++) {
		if (v[i].first >= e) {
			total++;
			e = v[i].second, s = v[i].first;
		}
	}
	cout << total << "\n";
}