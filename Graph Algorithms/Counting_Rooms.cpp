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

vector<vector<int>> temp = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
void dfs(vector<vector<char>> &arr, int row, int col, vector<vector<bool>> &vis)
{
    vis[row][col] = true;

    for (auto &it : temp)
    {
        int new_row = row + it[0];
        int new_col = col + it[1];

        if (new_row < n and new_col < m and new_row >= 0 and new_col >= 0)
        {
            if (!vis[new_row][new_col] and arr[new_row][new_col] != '#')
            {
                dfs(arr, new_row, new_col, vis);
            }
        }
    }
}
void lesgo()
{

    cin >> n >> m;
    int cnt = 0;

    vector<vector<char>> arr(n, vector<char>(m));

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != '#' and !vis[i][j])
            {
                dfs(arr, i, j, vis);
                cnt++;
            }
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
