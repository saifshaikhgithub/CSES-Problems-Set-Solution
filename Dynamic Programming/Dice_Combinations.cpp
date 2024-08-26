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

const int mod = 1e9 + 7;
int dp[1000001];
int solve(vector<int> &arr, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }
    int take = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= target)
        {
            take = (take + solve(arr, target - arr[i])) % mod;
        }
    }

    return dp[target] = take;
}
void lesgo()
{
    int n;
    cin >> n;

    vector<int> arr = {1, 2, 3, 4, 5, 6};

    memset(dp, -1, sizeof(dp));

    cout << solve(arr, n) << endl;
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
