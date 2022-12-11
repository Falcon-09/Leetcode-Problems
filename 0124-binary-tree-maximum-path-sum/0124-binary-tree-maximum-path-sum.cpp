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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        f(root,ans);
        return ans;
    }
    
    int f(TreeNode* r,int &mx){
        if(!r) return 0;
        int l = max(0,f(r->left,mx));
        int rt = max(0,f(r->right,mx));
        mx = max(mx,l+rt+r->val);
        return max(l,rt)+r->val;
    }
};