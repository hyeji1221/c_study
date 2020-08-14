#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return false;
	return false;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, string>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
}