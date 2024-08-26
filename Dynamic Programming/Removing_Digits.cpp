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
int solve(int target)
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
    int temp = target;
    while (temp > 0)
    {

        int digit = temp % 10;

        if (digit > 0)
        {
            mini = min(mini, 1 + solve(target - digit));
        }

        temp /= 10;
    }

    return dp[target] = mini;
}
void lesgo()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << solve(n) << endl;
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