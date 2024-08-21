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

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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
    if (n == 1 and m == 1)
    {
        if (arr[0][0] == 'A')
        {
            YES
                    cout
                << 0 << endl;
            return;
        }
    }

    // calculating the shortest path from the A to all the boundaries...

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> direction(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<pair<int, int>> esc;
    // vector<vector<int>> mon_dist(n, vector<int>(m, INT_MAX));
    int st_row = -1;
    int st_col = -1;
    int cnt = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    // queue<pair<int, int>> mon;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) and arr[i][j] == '.')
            {
                esc.push_back({i, j});
            }
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) and arr[i][j] == 'A')
            {
                cnt1++;
            }
            if (arr[i][j] == '.')
            {
                cnt2++;
            }
            if (arr[i][j] == 'A')
            {
                st_row = i;
                st_col = j;
            }
            if (arr[i][j] == 'M')
            {
                cnt++;
            }
        }
    }
    if (cnt1 > 0 and cnt2 == 0)
    {
        YES
                cout
            << 0 << endl;
        return;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    q.push({0, {st_row, st_col}});

    pair<int, int> st = {st_row, st_col};

    dist[st_row][st_col] = 0;

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
            if (new_col < m and new_row < n and new_row >= 0 and new_col >= 0 and arr[new_row][new_col] != '#' and arr[new_row][new_col] != 'M')
            {
                if (d + 1 < dist[new_row][new_col])
                {
                    dist[new_row][new_col] = d + 1;
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

    vector<pair<pair<int, int>, string>> store;
    for (auto &it : esc)
    {
        int dt_row = it.first;
        int dt_col = it.second;
        if (dist[dt_row][dt_col] != INT_MAX)
        {
            auto curr = it;
            string path;
            while (curr != st)
            {
                path.push_back(direction[curr.first][curr.second]);
                curr = parent[curr.first][curr.second];
            }
            reverse(path.begin(), path.end());
            store.push_back({{it.first, it.second}, path});
        }
    }

    // for (auto &it : store)
    // {
    //     cout << it.first.first << " " << it.first.second << " -> " << it.second << endl;
    // }

    // bfs from each monster to the boundary cells

    if (cnt == 0)
    {
        for (auto &it : esc)
        {
            if (dist[it.first][it.second] != INT_MAX)
            {
                YES

                    for (const auto &s : store)
                {
                    if (s.first == make_pair(it.first, it.second))
                    {
                        cout << s.second.size() << endl;
                        cout << s.second << endl;
                        return;
                    }
                }
            }
        }
    }

    vector<vector<set<int>>> b_dist(n, vector<set<int>>(m));
    vector<pair<int, int>> monsters;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && arr[i][j] == '.')
            {
                b_dist[i][j] = set<int>();
            }
            if (arr[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
        }
    }

    for (const auto &monster : monsters)
    {
        vector<vector<int>> dist(n, vector<int>(m, LLONG_MAX));
        queue<pair<int, int>> bfs_queue;

        int start_row = monster.first;
        int start_col = monster.second;

        dist[start_row][start_col] = 0;
        bfs_queue.push({start_row, start_col});

        while (!bfs_queue.empty())
        {
            auto it = bfs_queue.front();
            bfs_queue.pop();

            int row = it.first;
            int col = it.second;
            int curr_dist = dist[row][col];

            for (auto &d : dir)
            {
                int new_row = row + d[0];
                int new_col = col + d[1];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                    (arr[new_row][new_col] == '.' || arr[new_row][new_col] == 'A' || arr[new_row][new_col] == 'M') &&
                    dist[new_row][new_col] == LLONG_MAX)
                {
                    dist[new_row][new_col] = curr_dist + 1;
                    bfs_queue.push({new_row, new_col});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && arr[i][j] == '.')
                {
                    if (dist[i][j] != LLONG_MAX)
                    {
                        b_dist[i][j].insert(dist[i][j]);
                    }
                }
            }
        }
    }

    // cout << "Distances from monsters to boundary '.' cells:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && arr[i][j] == '.')
    //         {
    //             cout << "Cell (" << i << ", " << j << "):";
    //             if (!b_dist[i][j].empty())
    //             {
    //                 for (const auto &dist : b_dist[i][j])
    //                 {
    //                     cout << " " << dist;
    //                 }
    //             }
    //             cout << endl;
    //         }
    //     }
    // }
    bool flag = false;
    for (const auto &it : esc)
    {
        int row = it.first;
        int col = it.second;

        if (dist[row][col] != INT_MAX)
        {

            if (b_dist[row][col].empty())
            {
                YES;

                for (const auto &s : store)
                {
                    if (s.first == make_pair(row, col))
                    {
                        cout << s.second.size() << endl;
                        cout << s.second << endl;

                        flag = true;
                        return;
                    }
                }

                return;
            }
            int d = *b_dist[row][col].begin();
            if (d > dist[row][col])
            {
                YES;

                for (const auto &s : store)
                {
                    if (s.first == make_pair(row, col))
                    {
                        cout << s.second.size() << endl;
                        cout << s.second << endl;

                        flag = true;
                        return;
                    }
                }
            }
        }
    }
    if (!flag)
    {
        NO
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
