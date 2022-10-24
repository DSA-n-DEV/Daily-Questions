// Author- Ankur Gupta
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> Transform_To_X(n, 0), Transform_To_Y(n, 0);
    // Initial idea is to transform all letters to x from left to right
    // and transform all letters to y from right to left
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'x')
            Transform_To_X[i]++;
        if (i > 0)
            Transform_To_X[i] += Transform_To_X[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != 'y')
            Transform_To_Y[i]++;
        if (i < n - 1)
            Transform_To_Y[i] += Transform_To_Y[i + 1];
    }
    ll ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, Transform_To_X[i] + Transform_To_Y[i] - 1);
        // We are subtracting 1 from the Sum of both because it doesn't matter if there is x or y at that index.
        // In case the character is x at index i, it will add an operation 1 in Transform_Y and in case character is Y at index i, it will add an operation 1 in Transform_X.
        // So In both cases, there will be addition of only 1.
    }
    cout << ans << endl;
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