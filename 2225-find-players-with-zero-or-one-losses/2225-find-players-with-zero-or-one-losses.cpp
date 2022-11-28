class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        
        map<int,int> l;
        
        for(auto x:arr){
            int loss = x[1];
            l[loss]++;
        }
        vector<int> tmp;
        unordered_map<int,int> vis;
        for(auto x:arr){
            int win = x[0];
            if(l.find(win)==l.end() and !vis[win]){
                vis[win] = 1;
                tmp.push_back(win);
            }
        }
        ans.push_back(tmp);
        tmp.clear();
        for(auto x:l){
            if(x.second==1){
                tmp.push_back(x.first);
            }
        }
        ans.push_back(tmp);
        for(int i=0;i<ans.size();i++) sort(ans[i].begin(),ans[i].end());
        return ans;
    }
};