#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void lesgo()
{
    int n;
    cin >> n;
    vector<pair<int, int>> store;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        store.push_back({a, 1});
        store.push_back({b, -1});
    }

    sort(store.begin(), store.end());

    int current_customers = 0;
    int max_customers = 0;

    // for (auto &it : store)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    for (auto &event : store)
    {
        current_customers += event.second;
        max_customers = max(max_customers, current_customers);
    }

    cout << max_customers << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}