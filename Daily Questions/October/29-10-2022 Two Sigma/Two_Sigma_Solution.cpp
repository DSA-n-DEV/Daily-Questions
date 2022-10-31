// Author - Ankur Gupta
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll Rows[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
ll Cols[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool CheckIfInside(ll x, ll y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
        return true;
    }
    return false;
}
double FindProbability(ll rows, ll cols, ll steps)
{
    vector<vector<double>> ChessBoard(8, vector<double>(8, 0.0));
    ChessBoard[rows][cols] = 1.0;
    for (int step = 0; step < steps; step++)
    {
        vector<vector<double>> Chess_Board_Modified(8, vector<double>(8, 0.0));
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                for (int direction = 0; direction < 8; direction++)
                {
                    ll newx = row + Rows[direction];
                    ll newy = col + Cols[direction];
                    if (CheckIfInside(newx, newy))
                    {
                        Chess_Board_Modified[newx][newy] += ChessBoard[row][col] / 8.0;
                        // We are dividing by 8 cause there are 8 ways to move from row col to any other cell
                    }
                }
            }
        }
        ChessBoard = Chess_Board_Modified;
    }
    double ans = 0.0;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            ans += ChessBoard[row][col];
        }
    }
    return ans;
}
void solve()
{
    ll x, y, steps;
    cin >> x >> y >> steps;
    cout << FindProbability(x, y, steps) << endl;
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