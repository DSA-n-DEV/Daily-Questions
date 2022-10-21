// Solved by Ankur.

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
    priority_queue<ll, vector<ll>, greater<ll>> pq; // Making a min-heap to get minimum value
    for (int i = 0; i <= min(n - 1, k); i++)
    {
        // We took min(n - 1, k) to avoid the case where k equals to n
        // TC = O(k)
        pq.push(v[i]);
    }
    ans.push_back(pq.top());
    pq.pop();
    for (int i = k + 1; i < n; i++)
    {
        // We are adding one element and popping the smallest element from the min heap
        pq.push(v[i]);
        ans.push_back(pq.top());
        pq.pop();
        // TC = O((n - k) * log(k))
    }
    // All the remaining elements will be popped out and added to the ans vector
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    // Printing the answer vector
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    // Total Time Complexity - O(k) + O((n - k) * log(k))
    // Total Space - O(k) for minheap
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