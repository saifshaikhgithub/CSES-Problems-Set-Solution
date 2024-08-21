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

int find1(int node, vector<int> &parent)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = find1(parent[node], parent);
}

void union1(int x, int y, vector<int> &rank, vector<int> &parent)
{
    int x_parent = find1(x, parent);
    int y_parent = find1(y, parent);

    if (x_parent != y_parent)
    {
        if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
}

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

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (auto &it : mp)
    {
        int u = it.first;
        for (int v : it.second)
        {
            union1(u, v, rank, parent);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        parent[i] = find1(i, parent);
    }

    map<int, int> mp1;

    for (int i = 1; i <= n; i++)
    {
        mp1[parent[i]]++;
    }

    // for (auto &it : parent)
    // {
    //     cout << it << " ";
    // }
    vector<int> ans;
    for (auto &it : mp1)
    {
        ans.push_back(it.first);
    }

    // for (auto &it : ans)
    // {
    //     cout << it << " ";
    // }

    cout << mp1.size() - 1 << endl;

    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}