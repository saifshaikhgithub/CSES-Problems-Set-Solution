#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PB push_back
#define int long long
#define vi vector<int>

void lesgo()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        int node = it.second;
        int d = it.first;

        if (d > dist[node])
            continue;

        for (auto &child : mp[node])
        {
            int dis = child.second;
            int chi = child.first;

            if (d + dis < dist[chi])
            {
                dist[chi] = d + dis;
                q.push({dist[chi], chi});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}
