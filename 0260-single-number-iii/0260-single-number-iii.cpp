class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        long long xor2 = 0;
        for(auto x:nums) xor2^=x;
        
        int rb = xor2&(-xor2);
        
        vector<int> ans(2);
        
        for(auto x:nums){
            if((rb&x)==0){
                ans[0]^=x;
            }else{
                ans[1]^=x;
            }
        }
        
        return ans;
    }
};