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
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        map<int,int> mp;
        
        for(int i=0;i<in.size();i++){
            mp[in[i]] = i;
        }
        
        return f(in,0,in.size()-1,p,0,p.size()-1,mp);
    }
    
    TreeNode* f(vector<int> &in,int is,int ie,vector<int> &p,int ps,int pe,map<int,int>&mp){
        if(is>ie || ps>pe) return NULL;
        
        TreeNode* root = new TreeNode(p[pe]);
        int inr = mp[p[pe]];
        int lc = inr-is;

        root->left = f(in,is,inr-1,p,ps,ps+lc-1,mp);
        root->right = f(in,inr+1,ie,p,ps+lc,pe-1,mp);
        
        return root;
    }
};