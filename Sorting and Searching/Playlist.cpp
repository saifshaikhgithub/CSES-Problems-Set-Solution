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

    vi arr(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    map<int, int> mp;

    // set<int> st;

    int left = 0;
    int right = 0;
    int maxi = 1;
    while (right < n)
    {

        mp[arr[right]]++;

        while (mp.size() != right - left + 1 and left < right)
        {

            mp[arr[left]]--;

            if (mp[arr[left]] == 0)
            {
                mp.erase(arr[left]);
            }

            left++;
        }

        maxi = max(maxi, (int)mp.size());

        right++;
    }

    cout << maxi << endl;
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
