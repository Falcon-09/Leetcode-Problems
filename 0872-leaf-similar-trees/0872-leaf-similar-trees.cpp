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
    
    void f(TreeNode* r,vector<int> &v){
        if(!r) return;
        if(!r->left and !r->right) {
            v.push_back(r->val);
            return;
        }
        f(r->left,v);
        f(r->right,v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1,s2;
        f(root1,s1);
        f(root2,s2);
        
        return s1==s2;
    }
};