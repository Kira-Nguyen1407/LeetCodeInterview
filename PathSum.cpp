#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        static int sum = 0;
        sum = sum + root->val;

        if (sum == targetSum)
            return true;

        if (!root->left)
        {
            sum = sum - root->val;
        }

        if (!hasPathSum(root->left, targetSum))
        {
            return hasPathSum(root->right, targetSum);
        }

        return true;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    Solution *s = new Solution();
    int targetSum = 1;

    cout << s->hasPathSum(root, targetSum) << endl;

    delete root;
    delete s;
    return 0;
}