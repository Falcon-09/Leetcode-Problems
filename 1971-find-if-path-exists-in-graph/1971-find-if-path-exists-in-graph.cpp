class Solution {
public:
    
    bool dfs(int src,int dst,map<int,vector<int>> &g,vector<int> &vis){
        vis[src] = 1;
        
        for(auto nbr:g[src]){
            if(!vis[nbr]){
                vis[nbr] = 1;
                if(nbr==dst) return true;
                if(dfs(nbr,dst,g,vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        
        if(source==dest) return true;
        
        map<int,vector<int>> g;
        
        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        vector<int> vis(n,0);
        
        return dfs(source,dest,g,vis);
    }
};