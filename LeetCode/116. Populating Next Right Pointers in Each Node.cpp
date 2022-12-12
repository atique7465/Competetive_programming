/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<Node*, int> cn = q.front(); q.pop();
            if(!q.empty() && q.front().second == cn.second) cn.first->next = q.front().first;
            if(cn.first->left != NULL) q.push({cn.first->left, cn.second+1});
            if(cn.first->right != NULL) q.push({cn.first->right, cn.second+1});
        }
        return root;
    }
};