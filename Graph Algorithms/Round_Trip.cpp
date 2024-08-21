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

bool dfs(int node, int parent, vector<int> &path, vector<bool> &vis, unordered_map<int, int> &parentMap, vector<vector<int>> &adj)
{
    vis[node] = true;
    path.push_back(node);
    parentMap[node] = parent;

    for (auto &child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node, path, vis, parentMap, adj))
            {
                return true;
            }
        }
        else if (child != parent)
        {
            path.push_back(child);

            int curr = node;
            int cnt = 0;
            vector<int> ans;
            while (curr != child)
            {
                ans.push_back(curr);
                curr = parentMap[curr];
            }

            cout << ans.size() + 2 << endl;
            for (auto &it : ans)
            {
                cout << it << " ";
            }

            cout << child << " " << ans[0] << endl;

            return true;
        }
    }

    path.pop_back();
    return false;
}

void lesgo()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    unordered_map<int, int> parentMap;
    vector<int> path;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, path, vis, parentMap, adj))
            {
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}