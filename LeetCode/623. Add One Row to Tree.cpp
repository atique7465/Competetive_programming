/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int gVal = 0;
    int gDepth = 0;
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {

        gVal = val;
        gDepth = depth;

        if (gDepth == 1) {
            return new TreeNode(gVal, root, nullptr);
        }

        addOneRowUtil(root, 1);
        return root;
    }

    void addOneRowUtil(TreeNode *root, int depth) {

        if (depth + 1 == gDepth) {
            TreeNode *leftNode = new TreeNode(gVal, root->left, nullptr);
            TreeNode *rightNode = new TreeNode(gVal, nullptr, root->right);
            root->left = leftNode;
            root->right = rightNode;
            return;
        }

        if (root->left != nullptr) addOneRowUtil(root->left, depth + 1);
        if (root->right != nullptr) addOneRowUtil(root->right, depth + 1);
    }
};