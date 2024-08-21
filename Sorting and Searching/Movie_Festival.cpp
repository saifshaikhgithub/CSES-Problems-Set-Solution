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

    vector<pair<int, int>> store;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        store.push_back({b, a});
    }

    sort(store.begin(), store.end());
    int cnt = 1;
    // for (auto &it : store)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    int departure = store[0].first;
    for (int i = 1; i < store.size(); i++)
    {
        if (store[i].second >= departure)
        {
            cnt++;
            departure = store[i].first;
        }
    }

    cout << cnt << endl;
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
