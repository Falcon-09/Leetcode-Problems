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
    
    int f(TreeNode* r){
        if(!r) return 0;
        int lc = f(r->left);
        int rc = f(r->right);
        return 1+lc+rc;
    }
    
    int countNodes(TreeNode* root) {
        return f(root);
    }
};