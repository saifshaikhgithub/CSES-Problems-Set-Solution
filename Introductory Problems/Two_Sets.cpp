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

    int sum1 = n * (n + 1) / 2;

    if (sum1 % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }

    // cout << prefix[n] << endl
    //      << endl;

    vector<int> vis(n + 1, false);

    int target = sum1 / 2;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int left = 0;
    int right = 0;
    int sum2 = 0;
    while (right < n)
    {
        sum2 += arr[right];
        vis[right] = true;

        while (sum2 > target and left <= right)
        {
            vis[left] = false;

            sum2 -= arr[left];
            left++;
        }

        if (sum2 == target)
        {
            break;
        }
        right++;
    }

    // for (auto &it : vis)
    // {
    //     cout << it << " ";
    // }

    YES

        vector<int>
            ans1;
    vector<int> ans2;

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            ans1.push_back(arr[i]);
        }
        else
        {
            ans2.push_back(arr[i]);
        }
    }
    cout << ans1.size() << endl;
    for (auto &it : ans1)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << ans2.size() << endl;
    for (auto &it : ans2)
    {
        cout << it << " ";
    }
    cout << endl;
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
