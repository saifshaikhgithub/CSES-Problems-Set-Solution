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
int dp[1000001];
int solve(vector<int> &arr, int target)
{
    if (target == 0)
    {
        return 0;
    }

    if (target < 0)
    {
        return INT_MAX;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= target)
        {
            int take = 1 + solve(arr, target - arr[i]);

            if (take != INT_MAX)
            {
                mini = min(take, mini);
            }
        }
    }

    return dp[target] = mini;
}
void lesgo()
{
    int n, k;
    cin >> n >> k;

    vi arr(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    if (solve(arr, k) == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << solve(arr, k) << endl;
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
