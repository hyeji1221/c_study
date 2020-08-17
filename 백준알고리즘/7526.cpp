#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector <int> v[1000];
int visit[1000][1000] = { 0, };
queue <pair<int, int>>q;
int m, n; //m은 가로 n은 세로
int sum = 0;
int arrx[4] = { -1,1,0,0 };
int arry[4] = { 0,0,-1,1 };
void bfs()
{
    while (!q.empty()) {
        int q_size = q.size();
        int check = 0;
        for (int i = 0; i < q_size; i++) {
            int first = q.front().first; //1의 좌표값
            int second = q.front().second;
            q.pop();
            visit[first][second] = 1;
            for (int j = 0; j < 4; j++) {
                int nextx = first + arrx[j];
                int nexty = second + arry[j];
                if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
                if (visit[nextx][second] == 0 && v[nextx][second] == 0) {
                    visit[nextx][second] = 1;
                    v[nextx][second] = 1;
                    check = 1;
                    q.push(make_pair(nextx, second));
                }
                if (visit[first][nexty] == 0 && v[first][nexty] == 0) {
                    visit[first][nexty] = 1;
                    v[first][nexty] = 1;
                    check = 1;
                    q.push(make_pair(first, nexty));
                }
            }
            
        }
        if (check)
            sum++;
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            v[i].push_back(num);
            if (num == 1)
                q.push(make_pair(i, j)); // 1의 위치를 저장
        }
    }

    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << sum << "\n";
    

}