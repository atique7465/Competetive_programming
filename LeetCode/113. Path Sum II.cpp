#include <bits/stdc++.h>

using namespace std;

/**
 * Easy Recursion
 * Runtime: 11 ms
 * Memory Usage: 19.9 MB
 */

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

    vector<vector<int>> result;
    vector<int> path;
    int gTargetSum;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        gTargetSum = targetSum;
        solve(root, 0);
        return result;
    }

    void solve(TreeNode *root, int currSum) {

        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        currSum += root->val;

        if (root->left == nullptr && root->right == nullptr && currSum == gTargetSum) {
            result.push_back(path);
        }

        solve(root->left, currSum);;
        solve(root->right, currSum);

        path.pop_back();
    }
};