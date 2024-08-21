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
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));

    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    pair<int, int> st;
    pair<int, int> dt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'A')
            {
                st = {i, j};
            }
            if (arr[i][j] == 'B')
            {
                dt = {i, j};
            }
        }
    }
    q.push({0, st});
    vector<vector<int>> dist(n, vector<int>(m, LLONG_MAX));

    dist[st.first][st.second] = 0;

    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<char>> direction(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        int d = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int new_row = row + dir[i][0];
            int new_col = col + dir[i][1];

            if (new_row < n && new_col < m && new_row >= 0 && new_col >= 0 && arr[new_row][new_col] != '#')
            {
                int dis = 1;

                if (d + dis < dist[new_row][new_col])
                {
                    dist[new_row][new_col] = d + dis;
                    q.push({dist[new_row][new_col], {new_row, new_col}});
                    parent[new_row][new_col] = {row, col};

                    if (i == 0)
                        direction[new_row][new_col] = 'D';
                    else if (i == 1)
                        direction[new_row][new_col] = 'U';
                    else if (i == 2)
                        direction[new_row][new_col] = 'R';
                    else
                        direction[new_row][new_col] = 'L';
                }
            }
        }
    }

    if (dist[dt.first][dt.second] == LLONG_MAX)
    {
        NO
    }
    else
    {
        YES;
        cout << dist[dt.first][dt.second] << endl;

        string path;
        auto curr = dt;
        while (curr != st)
        {
            path.push_back(direction[curr.first][curr.second]);
            curr = parent[curr.first][curr.second];
        }

        reverse(path.begin(), path.end());
        cout << path << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}