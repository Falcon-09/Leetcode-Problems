class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=0;
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            
            if(mp.find(s%k)==mp.end()) mp[s%k]=i+1;
            else if(mp[s%k]<i){
                return true;
            }
        }
        
        return false;
    }
};