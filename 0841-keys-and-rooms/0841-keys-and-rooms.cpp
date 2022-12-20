class Solution {
public:
    
    void dfs(int src,map<int,vector<int>> &g,vector<int> &vis){
        vis[src]=1;
        
        for(auto nbr:g[src]){
            if(!vis[nbr]){
                vis[nbr]=1;
                dfs(nbr,g,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n = r.size();
        
        vector<int> vis(n,0);
        
        map<int,vector<int>> g;
        
        for(int i=0;i<n;i++){
            for(auto x:r[i]){
                g[i].push_back(x);
            }
        }
        
        dfs(0,g,vis);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        
        return true;
    }
};