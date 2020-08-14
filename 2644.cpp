#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
int visit[101];
int n, m, start, finish;
queue <int> q;
void bfs() // 거리계산은 대부분 bfs 이용
{
    while (!q.empty()) {
        int num = q.front(); 
        q.pop();
        for (int i = 0; i < n; i++) {
            if (arr[num][i] == 1 && visit[i] == 0) {
                visit[i] = visit[num] + 1;
                q.push(i);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> start >> finish;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    q.push(start);
    visit[start] = 1;
    bfs();
    cout << visit[finish]-1;
    return 0;
}