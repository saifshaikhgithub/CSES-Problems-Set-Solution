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

void dfs(unordered_map<int, vector<int>> &mp, int node, vector<int> &count_sub)
{
    count_sub[node] = 0;

    for (auto &it : mp[node])
    {
        dfs(mp, it, count_sub);

        count_sub[node] += (1 + count_sub[it]);
    }
}
void lesgo()
{
    int n;
    cin >> n;

    vi arr(n);
    unordered_map<int, vector<int>> mp;

    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a].push_back(i + 1);
    }
    vector<int> ans;
    vector<int> count_sub(n + 1, 0);

    dfs(mp, 1, count_sub);

    for (int i = 1; i <= n; i++)
    {
        cout << count_sub[i] << " ";
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
