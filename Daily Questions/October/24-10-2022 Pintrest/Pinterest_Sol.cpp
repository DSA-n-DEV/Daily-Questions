// Author - Ankur Gupta
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
bool Knows(ll a, ll b)
{
    // O(1) operation returning true or false
}
void solve()
{
    ll n;
    cin >> n;
    // N is the total number of people
    ll celebrity = 0;
    // Obviously if A person knows B, then A can't be the celebrity, So we will take B as the celebrity
    // Though, we are not sure if B is the celebrity but B sure is a candidate for becoming the celebrity
    for (int i = 1; i < n; i++)
    {
        if (Knows(celebrity, i))
        {
            celebrity = i;
        }
    }
    // Now we need to check if our chosen celebrity is actually a celebrity or not
    // This part is actually a twist in this question 🌝
    for (int i = 0; i < n; i++)
    {
        if ((i != celebrity && Knows(celebrity, i)) || !Knows(i, celebrity))
        {
            // Obviously, if the celebrity knows any other person or Even one person doesn't know our chosen celebrity, He will not be a celebrity. So we will return -1
            cout << "No Celeb in the show, Go Home" << endl;
            return;
        }
    }
    cout << celebrity << endl;
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