#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define vi vector<int>

void lesgo()
{
    int n, k;
    cin >> n >> k;

    multiset<int> arr;
    vi brr(k);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.insert(x);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> brr[i];
    }

    for (int i = 0; i < k; i++)
    {
        int ele = brr[i];

        auto it = arr.upper_bound(ele);

        if (it == arr.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            --it;
            cout << *it << endl;
            arr.erase(it);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}
