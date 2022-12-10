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
#define ll long long
class Solution {
public:
    
    ll ts = 0,ans = 0,s = 0;
    
    void f1(TreeNode* r){
        if(!r) return;
        ts+=r->val;
        f1(r->left);
        f1(r->right);
    }
    
    ll f2(TreeNode* r){
        if(!r) return 0;
        ll ls = f2(r->left);
        ll rs = f2(r->right);
        s = ls+rs+r->val;
        ans = max(ans,s*(ts-s)*1ll);
        return s;
    }
    
    int maxProduct(TreeNode* root) {
        int mod = 1e9+7;
        f1(root);
        // cout<<ts;
        f2(root);
        return ans%mod;
    }
};