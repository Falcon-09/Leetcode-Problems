class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<unordered_map<long long,long long>>dp(nums.size());
        long long ans=0;
        
        for(int i=1;i<nums.size();i++)
        {
            long long currele=nums[i];
            for(int j=i-1;j>=0;j--)
            {
                long long diff=currele-nums[j];   //check
                
                if(dp[j].find(diff)==dp[j].end())
                {
                    ans+=0;
                    dp[i][diff]=dp[i][diff]+1;
                }
                else
                {
                    ans+=dp[j][diff];
                    dp[i][diff]=dp[i][diff]+1+dp[j][diff];
                }
            }
        }
        return ans;
    }
};