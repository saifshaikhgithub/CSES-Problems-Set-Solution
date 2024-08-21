#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define REP(i, a, b) for (int i = a; i < b; i++)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define PB push_back
#define int long long

void lesgo()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int median;

    if (n % 2 != 0)
    {
        median = arr[n / 2];
    }
    else
    {
        median = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += abs(median - arr[i]);
    }

    cout << ans << endl;
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