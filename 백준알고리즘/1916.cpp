#include<iostream>
#include<queue>
#include<vector>

#define MAX 20010
#define INF 987654321
using namespace std;

int V, E, Start, finish;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void Dijkstra()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= V; i++) Dist[i] = INF;

    cin >> Start >> finish;
    Dijkstra();
    cout << Dist[finish];

    return 0;
}