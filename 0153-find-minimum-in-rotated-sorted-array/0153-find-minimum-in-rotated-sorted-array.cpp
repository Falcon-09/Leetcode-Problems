class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = 1e9;
        
        if(nums[0]<=nums[n-1] or n==1) return nums[0]; 
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[0]<=nums[mid]){
                lo = mid+1;
            }else{
                ans = min(ans,nums[mid]);
                hi = mid-1;
            }
        }
        
        return ans;
    }
};