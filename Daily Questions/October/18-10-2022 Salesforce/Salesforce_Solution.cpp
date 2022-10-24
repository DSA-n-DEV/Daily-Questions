// Solution by Ankur Gupta.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
TreeNode *FindAns(TreeNode *Tree1, TreeNode *Tree2)
{
    // Basic idea is we are adding the value of Tree2 in Tree1 and then return Tree1 as the answer
    if (Tree1 != NULL && Tree2 != NULL)
    {
        Tree1->data += Tree2->data;
        Tree1->left = FindAns(Tree1->left, Tree2->left);
        Tree1->right = FindAns(Tree1->right, Tree2->right);
    }
    else
    {
        if (Tree1 != NULL)
        {
            return Tree1;
        }
        return Tree2;
    }
    return Tree1;
}
void solve()
{
    // We will take Input From the user
    TreeNode *Tree1 = new TreeNode(1);
    TreeNode *Tree2 = new TreeNode(1);
    // Its just a random input
    FindAns(Tree1, Tree2);
    // Print(Tree1)
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
