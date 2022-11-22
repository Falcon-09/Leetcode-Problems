class Solution {
public:
    
    int dp[10005];
    
    int f(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int ans = 1e9;
        
        for(int i=1;i*i<=n;i++){
            ans = min(ans,1+f(n-i*i));
        }
        
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        
        return f(n);
    }
};