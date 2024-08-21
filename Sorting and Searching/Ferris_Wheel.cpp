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

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;
    int cnt = 0;
    while (left < right)
    {

        if (arr[left] + arr[right] <= k)
        {
            // cout << arr[left] << " " << arr[right] << endl;
            cnt++;
            left++;
            right--;
        }
        else
        {
            // cout << arr[right] << endl;
            cnt++;
            right--;
        }
        if (left == right)
        {
            // cout << arr[left] << endl;
            cnt++;
            left++;
            right--;
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