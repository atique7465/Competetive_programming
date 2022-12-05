// setting boundery values for every sub tree
class Solution_02 {
    vector<int> v;
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
    
    bool solve(TreeNode* root, long min, long max){
        if(root == NULL) return true;
        if(root->val <= min || root->val >= max) return false;
        return solve(root->left, min, root->val) & solve(root->right, root-> val, max);        
    }
    
};

class Solution_01_preorder {
    vector<int> v;
public:
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i = 0; i < v.size()-1; i++) if(v[i] >= v[i+1]) return false;
        return true;
    }
    
    void inOrder(TreeNode* root){
        if(root == NULL) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    
};