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

void lesgo()
{
    int n, m;

    cin >> n >> m;

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    vector<int> dist(n + 1, INT_MAX);

    vector<int> parent(n + 1, -1);

    q.push({0, 1});

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        int node = it.second;
        int d = it.first;

        for (auto &it : mp[node])
        {
            int dis = 1;

            if (d + dis < dist[it])
            {
                dist[it] = d + dis;
                q.push({dist[it], it});
                parent[it] = node;
            }
        }
    }
    vector<int> path;
    if (dist[n] == INT_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    while (n != 1)
    {
        path.push_back(n);
        n = parent[n];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (auto &it : path)
    {
        cout << it << " ";
    }
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