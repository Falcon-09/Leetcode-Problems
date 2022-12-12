class Solution {
public:

    int dp[55];
    
    int f(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = f(n-1)+f(n-2);
    }

    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};