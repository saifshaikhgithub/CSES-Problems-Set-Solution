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
int n;
int cnt = 0;
vii temp = {{0, 1}, {1, 0}};
int dp[1001][1001];
int solve(vector<vector<char>> &arr, int row, int col)
{
    if (row >= n || col >= n || arr[row][col] == '*')
    {
        return 0;
    }
    if (row == n - 1 and col == n - 1)
    {
        return 1;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int path1 = solve(arr, row + 1, col);
    int path2 = solve(arr, row, col + 1);

    return dp[row][col] = (path1 + path2) % mod;
}

void lesgo()
{
    // int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));

    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(arr, 0, 0) << endl;

    // cout << cnt % mod << endl;
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