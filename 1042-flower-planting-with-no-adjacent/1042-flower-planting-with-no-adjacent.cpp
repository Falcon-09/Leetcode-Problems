class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& p) {
        map<int,vector<int>> mp;
        vector<int> ans(n);
        for(auto x:p){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        for(int i=1;i<=n;i++){
            vector<int> c(5,0);
            for(auto e:mp[i]){
                c[ans[e-1]]=1;
            }
            for(int j=1;j<=4;j++){
                if(c[j]==0){
                    ans[i-1]=j;
                    break;
                }
            }
        }
        
        return ans;
    }
};