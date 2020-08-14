#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#define Max 10000
using namespace std;
int visit[Max];
int n, start, finish;
bool is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	if (i == n)
		return 1; // 소수
}
int to_int(string s) // 문자열을 int로 바꾸는 함수
{
	int n = 0;
	for (int i = 0; i < 4; i++) {
		n = n * 10 + (s[i] - '0');
	}
	return n;
}

void bfs(int start) // 소수 변환 과정 거리 출력이므로 bfs 이용
{
	queue<int>q;
	q.push(start);
	visit[start] = 0; // visit을 0으로 방문했음을 표기
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) { // 4자리 숫자이므로
			string s = to_string(node);
			for (int j = 0; j < 10; j++) { // 0000~9999 까지
				s[i] = j + '0';
				int next = to_int(s);
				if (next >= 1000 && is_prime(next) && visit[next] == -1) {
					visit[next] = visit[node] + 1; 
					q.push(next);
				}
			}


		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(visit, -1, sizeof(visit));
		cin >> start >> finish;
		bfs(start);
		if (visit[finish] != -1) { //finish까지 방문을 했으면
			cout << visit[finish] << "\n";
		}
		else
			cout << "Impossible" << "\n";
	}
	
}