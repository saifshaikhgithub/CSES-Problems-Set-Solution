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
    int n;
    cin >> n;

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        mp[a].push_back(b);
    }

    int index = 0;

    queue<pair<int, int>> q;

    q.push({1, 0});
    int maxi = INT_MIN;
    while (!q.empty())
    {
        int s = q.size();

        while (s--)
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int idx = it.second;
            cout << node << " " << idx << endl;
            bool flag = false;
            maxi = max(maxi, idx);
            for (auto &child : mp[node])
            {
                if (!flag)
                {
                    q.push({child, 2 * idx + 1});
                    flag = true;
                }
                else
                {
                    q.push({child, 2 * idx + 2});
                    flag = false;
                }
            }
        }
    }

    cout << maxi << endl;
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
