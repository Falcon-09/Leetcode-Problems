class Solution {
public:

    int dp[105][105]; 
    
    int f(int i,int j,vector<vector<int>> &mat,int n,int m){
        if(j<0 or j>=m) return 1e9;
        if(i==n-1){
            return mat[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int op1 = mat[i][j] + f(i+1,j,mat,n,m);
        int op2 = mat[i][j] + f(i+1,j-1,mat,n,m);
        int op3 = mat[i][j] + f(i+1,j+1,mat,n,m);

        return dp[i][j] = min({op1,op2,op3});
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof(dp));
        int n = mat.size();
        int m = mat[0].size();
        int ans = 1e9;
        for(int i=0;i<m;i++){
            ans = min(ans,f(0,i,mat,n,m));
        }

        return ans;
    }
};