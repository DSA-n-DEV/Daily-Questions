// Author - Ankur Gupta
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
vector<ll> indegree(26, 0), outdegree(26, 0), present(26, 0);
vector<ll> adj[26];

void dfs(ll FirstChar, vector<ll> &visited)
{
    visited[FirstChar] = 1;
    for (auto it : adj[FirstChar])
    {
        if (!visited[it])
        {
            dfs(it, visited);
        }
    }
}
bool FindIfPossible(ll n, vector<string> &v)
{
    vector<ll> visited(26, 0);
    for (int i = 0; i < n; i++)
    {
        string current = v[i];
        ll len = current.size();
        ll First_Letter = current[0] - 'a';
        ll Last_Letter = current[len - 1] - 'a';
        present[First_Letter] = 1;
        present[Last_Letter];
        outdegree[First_Letter]++;
        indegree[Last_Letter]++;
        adj[First_Letter].push_back(Last_Letter);
    }
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] != outdegree[i])
        {
            return false;
        }
    }
    // To start finding the cycle, we will take the first character of the first string
    ll FirstChar = v[0][0] - 'a';
    dfs(FirstChar, visited);
    // Now we will check if all the strings have been visited or not
    for (int i = 0; i < 26; i++)
    {
        if (present[i] == 1 && !visited[i])
        {
            return false;
        }
    }
    return true;
}
void solve()
{

    // Point to be Noted :
    // v = ['a'] or v = ['aa'] will give Yes as answer as it will connect to itself
    ll n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bool ans = FindIfPossible(n, v);
    if (ans)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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