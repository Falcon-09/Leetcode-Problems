class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& r, int ex) {
        int n = r.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int diff = cap[i]-r[i];
            if(diff){
                pq.push(diff);
            }else {
                ans++;
            }
        }
        
        while(ex>0 and !pq.empty()){
            int t = pq.top();
            pq.pop();
            if(ex>=t) ex-=t,ans++;
        }
        
        return ans;
    }
};