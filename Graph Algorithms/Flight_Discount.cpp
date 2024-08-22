#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define REP(i, a, b) for (int i = a; i < b; i++)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define PB push_back
#define int long long
#define vi vector<int>
#define vii vector<vector<int>>

void dj(int src, unordered_map<int, vector<pair<int, int>>> &mp, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    dist[src] = 0;

    q.push({0, src});

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        int node = it.second;
        int dis = it.first;
        if (dis > dist[node])
        {
            continue;
        }

        for (auto &it : mp[node])
        {
            int child = it.first;
            int d = it.second;

            if (d + dis < dist[child])
            {
                dist[child] = d + dis;
                q.push({dist[child], child});
            }
        }
    }
}
void lesgo()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<pair<int, int>>> mp1;
    unordered_map<int, vector<pair<int, int>>> mp2;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        mp1[a].push_back({b, c});
        mp2[b].push_back({a, c});

        edges.push_back({a, b, c});
    }
    // for (auto &it : mp)
    // {
    //     cout << it.first << " -- ";

    //     for (auto &it1 : it.second)
    //     {
    //         cout << it1.first << " " << it1.second << " .... ";
    //     }

    //     cout << endl;
    // }

    vector<int> dist1(n + 1, LLONG_MAX);
    vector<int> dist2(n + 1, LLONG_MAX);

    dj(1, mp1, dist1);
    dj(n, mp2, dist2);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dist1[i] << " " << dist2[i] << endl;
    // }

    int mini = LLONG_MAX;

    for (auto &it : edges)
    {
        int u = get<0>(it);
        int v = get<1>(it);
        int wt = get<2>(it);
        if (dist1[u] != LLONG_MAX && dist2[v] != LLONG_MAX)
        {
            mini = min(mini, dist1[u] + dist2[v] + wt / 2);
        }
    }

    cout << mini << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     lesgo();
    // }
    lesgo();
    return 0;
}
