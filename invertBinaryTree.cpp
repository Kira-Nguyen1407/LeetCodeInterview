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
    TreeNode *invertTree(TreeNode *root)
    {
        static int count = 0;
        if (root == nullptr)
        {
            cout << "count: " << count << endl;
            return nullptr; // Return null for an empty tree
        }

        count++;

        // Swap the left and right subtrees recursively
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;
    
        return root;
    }

    // Function to print the tree (in-order traversal)
    void printTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
};

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution *solution = new Solution();

    TreeNode* invertedRoot = solution->invertTree(root);
    solution->printTree(invertedRoot);
    std::cout << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}