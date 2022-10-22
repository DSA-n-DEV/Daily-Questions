// Author - Ankur Gupta
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 1e9);
    dp[n] = 0;
    dp[n - 1] = 1;
    // We can directly write this as there are no common factors of (n) & (n - 1) ever
    // except if n == 2
    for (int i = n; i >= 0; i--)
    {
        ll num = i;
        if (i < n - 1)
        {
            dp[num] = min(dp[num], 1 + dp[num + 1]);
        }
        // Taking out the factors
        for (int j = 2; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                ll maxi = max(num / j, (long long)j);
                dp[maxi] = min(dp[maxi], 1 + dp[num]);
            }
        }
    }
    cout << dp[1] << endl;
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