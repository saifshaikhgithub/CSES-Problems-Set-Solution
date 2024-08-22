#include <bits/stdc++.h>
using namespace std;
#define int long long

void lesgo()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int right = n - 1;
    int cap = m;

    vector<int> prefix(n);
    prefix[0] = arr[0];
    // arr[0] > 0;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    if (arr[0] > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0 && prefix[i] != 0)
            {
                cout << 0 << endl;
                return;
            }
        }

        while (right >= 1)
        {
            if (arr[right] < 0)
            {
                cap = m;

                // cout << cap << " ";
            }
            else
            {
                cap -= arr[right];

                // cout << cap << " ";
            }

            if (cap < 0)
            {
                cout << 0 << endl;
                return;
            }

            right--;
        }
    }
    // else
    // {
    //     cap -= abs(arr[0]);
    // }
    if (arr[0] < 0)
    {
        cout << m - abs(arr[0]) + 1 << endl;
    }
    else
    {
        cout << cap - arr[0] + 1 << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lesgo();
    return 0;
}
