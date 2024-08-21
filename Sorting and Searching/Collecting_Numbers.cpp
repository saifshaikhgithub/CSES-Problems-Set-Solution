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

    vi arr(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    vector<pair<int, int>> store;

    for (int i = 0; i < n; i++)
    {
        store.push_back({arr[i], (i + 1)});
    }

    sort(store.begin(), store.end());

    int cnt = 1;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (store[i].second < idx)
        {
            cnt++;
        }

        idx = store[i].second;
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