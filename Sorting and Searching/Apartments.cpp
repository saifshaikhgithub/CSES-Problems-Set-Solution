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
    int n, m, k;
    cin >> n >> m >> k;

    vi arr(n);
    vi brr(m);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    REP(i, 0, m)
    {
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    int cnt = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j < m && brr[j] < arr[i] - k)
        {
            j++;
        }
        if (j < m && abs(brr[j] - arr[i]) <= k)
        {
            cnt++;
            j++;
        }
    }

    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}