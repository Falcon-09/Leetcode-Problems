class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tsk) {
        
        vector<vector<int>> ds;
        
        for(int i=0;i<tsk.size();i++){
            ds.push_back({tsk[i][0],tsk[i][1],i});
        }
        
        sort(ds.begin(),ds.end());
        
        vector<int> ans;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        long long cur = 0;
        
        int i = 0;
        
        while(i<ds.size() or !pq.empty()){
            if(pq.empty()){
                if(cur<ds[i][0]) {
                    cur = ds[i][0];
                }
            }
            
            while(i<ds.size() and cur>=ds[i][0]){
                pq.push({ds[i][1],ds[i][2]});
                i++;
            }
            
            auto p = pq.top();
            pq.pop();
            
            cur+=p.first;
            ans.push_back(p.second);
        }
        
        return ans;
    }
};