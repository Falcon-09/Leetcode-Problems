class Solution {
public:
    
    vector<int> ans;
    vector<int> cnt;
    map<int,vector<int>> g;
    
    void f1(int r,int pre){
        for(auto nbr:g[r]){
            if(nbr==pre) continue;
            f1(nbr,r);
            cnt[r]+=cnt[nbr];
            ans[r]+=ans[nbr]+cnt[nbr];
        }
        ++cnt[r];
    }
    
    void f2(int r,int pre){
        for(auto nbr:g[r]){
            if(nbr==pre) continue;
            ans[nbr] = ans[r]-cnt[nbr]+cnt.size()-cnt[nbr];
            f2(nbr,r);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans.resize(n,0);
        cnt.resize(n,0);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        f1(0,-1);
        f2(0,-1);
        
        return ans;
    }
};