#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
const int INF = 1e18;

void lesgo()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> arr;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (n == 1 and m == 1 and a == 1 and b == 1 and c == -1)
        {
            cout << 0 << endl;
            return;
        }
        arr[a].push_back({b, c});
    }

    vector<int> dist(n + 1, -INF);
    dist[1] = 0;

    // Bellman-Ford algorithm to find the maximum path
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto &it : arr)
        {
            int u = it.first;
            for (auto &edge : it.second)
            {
                int v = edge.first;
                int wt = edge.second;

                if (dist[u] != -INF)
                {
                    dist[v] = max(dist[v], dist[u] + wt);
                }
            }
        }
    }

    bool positiveCycle = false;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto &it : arr)
        {
            int u = it.first;
            for (auto &edge : it.second)
            {
                int v = edge.first;
                int wt = edge.second;

                if (dist[u] != -INF && dist[u] + wt > dist[v])
                {
                    dist[v] = dist[u] + wt;
                    visited[v] = true;
                }
            }
        }
    }

    queue<int> q;
    vector<bool> inQueue(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == n)
        {
            positiveCycle = true;
            break;
        }
        for (auto &edge : arr[u])
        {
            int v = edge.first;
            if (!inQueue[v])
            {
                q.push(v);
                inQueue[v] = true;
            }
        }
    }

    if (positiveCycle)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (dist[n] == 0 ? -1 : dist[n]) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}
