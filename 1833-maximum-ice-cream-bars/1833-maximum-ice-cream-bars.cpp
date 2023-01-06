class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int ans = 0;
        
        for(auto x:costs){
            if(coins>=x) ans+=1;
            if(coins>0) coins-=x;
        }
        
        return ans;
    }
};