class Solution {
public:
    int minStoneSum(vector<int>& arr, int k) {
        int n = arr.size();
        
        priority_queue<int> pq;
        
        for(auto x:arr) pq.push(x);
        
        while(!pq.empty() and k--){
            int t = pq.top();
            pq.pop();
            if(t%2==0) t/=2;
            else t/=2,t++;
            if(t) pq.push(t);
        }
        int ans = 0;
        
        while(!pq.empty()) {
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};