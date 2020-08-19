#include <iostream>
using namespace std;
int parent[100001];
int g, p; // g는 게이트의 수, p는 비행기의 수
int total = 0;

int findParent(int a) // 부모노드를 찾는 함수
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = findParent(parent[a]); // 재귀
}

void unionParent(int a, int b) // 부모노드 합치기
{
	a = findParent(a); //a의 부모 찾기
	b = findParent(b); //b의 부모 찾기
	if (a < b) parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> g >> p;
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= p; i++) {
		int n;
		cin >> n;
		int docking = findParent(n); // n의 부모노드를 찾아서 docking에 저장
		if (docking) {
			unionParent(docking, docking - 1); 
			//doking의 게이트 루트가 doking-1이 되게 한다.
			// 따라서 findParent 후 0이 되면 더이상 도킹할 게이트가 없다는 의미
			total++;
		}
		else
			break;
		
	}
	cout << total << "\n";
}