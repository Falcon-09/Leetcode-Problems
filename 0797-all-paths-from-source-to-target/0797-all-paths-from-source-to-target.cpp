class Solution {
public:
    
    void dfs(vector<vector<int>>&mat,vector<vector<int>>&ans,vector<int>& t,int src){
        t.push_back(src);
        if(src==mat.size()-1){
            ans.push_back(t);
        }else{
            for(auto x:mat[src]){
                dfs(mat,ans,t,x);
            }
        }
        t.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph,ans,path,0);
        return ans;
    }
};