class Solution {
public:
    
    int dp[10005];
    
    bool f(int i,vector<int> &arr){
        if(i>=arr.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=arr[i];j++){
            if(f(i+j,arr)) return dp[i] = true;
        }
        
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,arr);
    }
};