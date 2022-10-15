class Solution {
public:
    const static int N = 127;
    vector<vector<int>> dp;
    inline int getLen(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
    int helper(string& str,int left,int k){
        if(k < 0) return N;   
        if(left >= str.size() or str.size() - left <= k) return 0;  
        if(dp[left][k] != -1)return dp[left][k];
        
        int res = N,cnt[26] = {0};
        for(int j = left,freq = 0; j < str.size(); j++) {
            freq = max(freq, ++cnt[str[j] - 'a']);   
            res = min(res, 1 + getLen(freq) + helper(str,j + 1, k - (j - left + 1 - freq)));
        }
        
        return dp[left][k]= res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        dp = vector<vector<int>>(N,vector<int>(N,-1));
        return helper(s,0,k);
    }
};