// Author - Ankur Gupta
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll Find_Minimum_Window(string s, string t, map<char, ll> &mpp)
{
    ll ans = 1e9;
    ll left = 0;
    ll n = s.size();
    ll total_unique_char = 0;
    // we just need total_unique_char variable to get the size of our first window
    for (int ind = 0; ind < n; ind++)
    {
        if (mpp[s[ind]] > 0)
        {
            total_unique_char++;
        }
        mpp[s[ind]]--;
        if (total_unique_char == t.size())
        {
            while (mpp[s[left]] < 0)
            {
                mpp[s[left]]++;
                left++;
            }
            ans = min(ans, ind - left + 1);
        }
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    string t;
    map<char, ll> mpp;
    for (char c : s)
    {
        if (mpp.find(c) == mpp.end())
        {
            t += c;
            mpp[c]++;
        }
    }
    ll ans = Find_Minimum_Window(s, t, mpp);
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