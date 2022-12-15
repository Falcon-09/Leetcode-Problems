class Solution {
public:

    int dp[1005][1005];

    int f(int i,int j,string &s,string &t){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int yes = 0,no = 0;
        if(s[i]==t[j]) {
            yes = 1+f(i-1,j-1,s,t);
        }
        else {
            no = max(f(i-1,j,s,t),f(i,j-1,s,t));
        }

        return dp[i][j] = max(yes,no);
    }

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,m-1,s,t);
    }
};