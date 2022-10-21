#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> ans;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(v[i]);
    }
    ans.push_back(pq.top());
    pq.pop();
    for (int i = k; i < n; i++)
    {
        pq.push(v[i]);
        ans.push_back(pq.top());
        pq.pop();
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
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