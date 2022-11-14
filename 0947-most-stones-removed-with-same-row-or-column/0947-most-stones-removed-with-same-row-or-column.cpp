class DSU {
    public:
    vector<int> par;
    vector<int> rank;
    
    DSU(int n){
        par.resize(n,-1);
        rank.resize(n,-1);
    }
    
    int find(int node){
        if(par[node]==-1) return node;
        
        return (par[node] = find(par[node]));
    }
    
    void Union(int n1,int n2){
        int lx = find(n1);
        int ly = find(n2);
        
        if(lx!=ly){
            if(rank[lx]<rank[ly]){
                par[lx] = ly;
            }else if(rank[lx]>rank[ly]){
                par[ly] = lx;
            }else{
                par[ly] = lx;
                rank[lx]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        DSU *dsu = new DSU(20005);
        for(auto x:s){
            dsu->Union(x[0],x[1]+10001);
        }
        set<int> st;
        for(auto x:s){
            st.insert(dsu->find(x[0]));
        }
        
        int cmp = st.size();
        
        return s.size()-cmp;
    }
};