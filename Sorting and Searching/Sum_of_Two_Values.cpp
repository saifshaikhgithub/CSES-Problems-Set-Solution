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
    int n, x;
    cin >> n >> x;

    vi arr(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> store;

    for (int i = 0; i < n; i++)
    {
        store.push_back({arr[i], i + 1});
    }
    sort(store.begin(), store.end());

    int left = 0;
    int right = arr.size() - 1;
    bool flag = false;
    while (left < right)
    {
        if (store[left].first + store[right].first == x)
        {
            cout << store[left].second << " " << store[right].second << endl;
            flag = true;
            return;
        }

        if (store[left].first + store[right].first > x)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    if (!flag)
    {
        cout << "IMPOSSIBLE" << endl;
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