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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = maxDepth(root->left) + 1;
        int rightHeight = maxDepth(root->right) + 1;

        if(leftHeight > rightHeight){
            return leftHeight;
        }

        return rightHeight;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(21);
    root->left->left->left = new TreeNode(25);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution *solution = new Solution();
    cout << solution->maxDepth(root) << endl;

    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    delete solution;

    return 0;
}