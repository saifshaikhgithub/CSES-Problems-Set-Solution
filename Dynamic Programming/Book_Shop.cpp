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
    int n, k;
    cin >> n >> k;

    vi arr(n);
    vi brr(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }
    REP(i, 0, n)
    {
        cin >> brr[i];
    }

    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= arr[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - arr[i]] + brr[i]);
        }
    }

    cout << dp[k] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lesgo();
    return 0;
}
