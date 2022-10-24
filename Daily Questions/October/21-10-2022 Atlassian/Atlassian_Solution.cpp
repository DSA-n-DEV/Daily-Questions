// Solution by Ankur Gupta.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> dpLeft(n, 1), dpRight(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
        {
            dpLeft[i] = dpLeft[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
        {
            dpRight[i] = dpRight[i + 1] + 1;
        }
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = max(dpLeft[i], dpRight[i]);
    }
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}