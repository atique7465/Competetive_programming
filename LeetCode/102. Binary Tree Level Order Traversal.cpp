class Solution_02_dfs {
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
    
    void dfs(TreeNode* root, int height){
        if(root == NULL) return;
        if(res.size() < height) res.push_back({root->val});
        else res[height - 1].push_back(root->val);
        dfs(root->left, height+1);
        dfs(root->right, height+1);
    }
};

class Solution_01_bfs {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL) return res;
            
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while(!q.empty()){
            pair<TreeNode*, int> top = q.front(); q.pop();
            if(res.size() < top.second) res.push_back({top.first->val});
            else res[top.second-1].push_back(top.first->val);
            if(top.first->left != NULL) q.push({top.first->left, top.second + 1});
            if(top.first->right != NULL) q.push({top.first->right, top.second + 1});
        }
        
        return res;
    }
};