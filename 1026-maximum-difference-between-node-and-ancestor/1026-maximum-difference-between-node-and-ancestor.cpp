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
    int res=0;
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        res=0;
        f(root,root->val,root->val);
        return res;
    }
    
    void f(TreeNode* r,int mx,int mn){
        if(!r) return;
        int pos = max(abs(mx-r->val),abs(mn-r->val));
        res = max(res,pos);
        mx = max(mx,r->val);
        mn = min(mn,r->val);
        f(r->left,mx,mn);
        f(r->right,mx,mn);
        return;
    }
};