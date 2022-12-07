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
    
    void f(TreeNode* r,int l,int h,int &ans){
        if(!r) return;
        if(r->val>=l and r->val<=h) {
            ans+=r->val;
        }
        f(r->left,l,h,ans);
        f(r->right,l,h,ans);
    }
    
    int rangeSumBST(TreeNode* root, int l, int h) {
        int ans = 0;
        f(root,l,h,ans);
        return ans;
    }
};