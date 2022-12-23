class Solution {
public:
    
    int dp[5005][2];
    
    int f(int i,vector<int> &arr,int buy){
        if(i>=arr.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int yes = 0,no = 0;
        if(buy){
            yes = -arr[i] + f(i+1,arr,0);
            no = f(i+1,arr,buy);
        }else{
            yes = arr[i] + f(i+2,arr,1);
            no = f(i+1,arr,buy);
        }
        
        return dp[i][buy] = max(yes,no);
    }
    
    int maxProfit(vector<int>& p) {
        int n = p.size();
        memset(dp,-1,sizeof(dp));
        return f(0,p,1);
    }
};