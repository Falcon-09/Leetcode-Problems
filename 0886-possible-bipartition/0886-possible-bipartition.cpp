class Solution {
public:
    
    bool bfs(map<int,vector<int>> &g,int src,vector<int> &vis){
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int n = q.front();
                q.pop();
                for(auto nbr:g[n]){
                    if(vis[nbr]==vis[n]) return false;
                    if(!vis[nbr]){
                        vis[nbr]=-vis[n];
                        q.push(nbr);
                    }
                }
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int,vector<int>> g;
        
        for(auto e:dislikes){
            int u = e[0];
            int v = e[1];
            
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        vector<int> vis(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!bfs(g,i,vis)) return false;
            }
        }
        
        return true;
    }
};