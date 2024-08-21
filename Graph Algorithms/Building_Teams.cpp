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

bool bfs(unordered_map<int, vi> &mp, int node, vector<int> &color)
{

    queue<int> q;

    color[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int node1 = q.front();

        q.pop();

        for (auto &child : mp[node1])
        {
            if (color[child] == 0)
            {
                color[child] = 3 - color[node1];
                q.push(child);
            }
            else if (color[child] == color[node1])
            {
                return false;
            }
        }
    }

    return true;
}
void lesgo()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vi> mp;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    vector<int> color(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (!bfs(mp, i, color))
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
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