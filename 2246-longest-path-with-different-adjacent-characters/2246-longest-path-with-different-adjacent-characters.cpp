class Solution {
public:
    
    map<int,vector<int>> g;
    int ans = 1;
    int dis[100005];
    
    void dfs(int src,string &s){
        dis[src] = 1;
        
        for(auto nbr:g[src]){
            dfs(nbr,s);
            if(s[src]!=s[nbr]){
                ans = max(ans,dis[src]+dis[nbr]);
                dis[src] = max(dis[src],dis[nbr]+1);
            }
        }
    }
    
    int longestPath(vector<int>& par, string s) {
        int n = par.size();
        
        for(int i=1;i<n;i++) {
            g[par[i]].push_back(i);
        }
        
        dfs(0,s);
        
        return ans;
    }
};