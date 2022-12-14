class Solution {
public:
    
    int dp[105];
    
    int f(int i,vector<int> &arr){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int yes = arr[i] + f(i+2,arr);
        int no = f(i+1,arr);
        
        return dp[i] = max(yes,no);
    }
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,arr);
    }
};