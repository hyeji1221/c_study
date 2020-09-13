#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>>v;
priority_queue<int> pq;
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int answer = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; // 데드라인, 컵라면 수
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end()); 
	for (int i = 0; i < n; i++) {
		int a = v[i].first;
		pq.push(-v[i].second); // 데드라인이 적은 것이 처음에 있기 때문에
		while (a < pq.size()) // 같은 데드라인에 컵라면 수가 여러개 있는 경우
			pq.pop(); // 음수 이므로 절대 값이 작은 수가 pop
	}
	while (!pq.empty()) {
		answer += pq.top();
		pq.pop();
	}
	cout << -answer << "\n";
	
	return 0;
}
