#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[101][101] = { 0, };
bool visit[100] = { 0, };
int v, e;
int total = 0;
void check(int n)
{
	total++;
	visit[n] = true;
	for (int i = 1; i <= v; i++)
		if (map[n][i] && !visit[i])
		{
			check(i);
		}

}
int main(void)
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	check(1);
	cout << total-1 << "\n";
	//for문에 걸리기 전 ++해놓은 것이 있으므로 1 빼기
	//2 1 ,1 2
}