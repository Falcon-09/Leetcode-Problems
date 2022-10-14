class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto it:f){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{src,0}});
        vector<int> dis(n,1e9);
        dis[src]=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int c = it.second.second;
            
            if(stops>k) continue;
            
            for(auto e:adj[node]){
                int adn = e.first;
                int ew = e.second;
                if(c+ew<dis[adn] and stops<=k){
                    dis[adn] = c+ew;
                    q.push({stops+1,{adn,dis[adn]}});
                }
            }
        }
        
        if(dis[dst]>=1e9) return -1;
        return dis[dst];
    }
};