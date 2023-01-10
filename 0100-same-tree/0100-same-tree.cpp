/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool f(TreeNode* p,TreeNode* q){
        if(!p and !q) return true;
        if(!p or !q) return false;
        if(p->val != q->val) return false;
        
        return f(p->left,q->left) and f(p->right,q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p,q);
    }
};