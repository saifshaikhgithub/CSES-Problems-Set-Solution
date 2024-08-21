#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PB push_back
#define int long long
#define vi vector<int>
const int INF = LLONG_MAX;

void floydWarshall(int n, vector<vector<int>> &dist)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void lesgo()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    floydWarshall(n, dist);

    for (int i = 1; i <= q; i++)
    {
        int a, b;

        cin >> a >> b;

        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}
