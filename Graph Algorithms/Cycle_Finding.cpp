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

    unordered_map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        mp[a].push_back({b, c});
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {

        for (auto &it : mp)
        {
            int u = it.first;

            for (auto &it1 : mp[u])
            {
                int child = it1.first;

                int d = it1.second;

                if (d + dist[u] < dist[child])
                {
                    dist[child] = d + dist[u];
                    parent[child] = u;
                }
            }
        }
    }

    for (auto &it : mp)
    {
        int u = it.first;

        for (auto &it1 : mp[u])
        {
            int child = it1.first;

            int d = it1.second;

            if (d + dist[u] < dist[child])
            {
                YES;
            }
        }
    }

    for (auto &it : parent)
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
