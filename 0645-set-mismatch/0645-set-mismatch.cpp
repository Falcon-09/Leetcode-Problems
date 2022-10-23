class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int d=-1,m=-1;
        for(auto x:nums) mp[x]++;
        for(int i=1;i<=n;i++){
            if(mp.count(i)){
                if(mp[i]==2) d=i;
            }else{
                m=i;
            }
        }
        
        return {d,m};
    }
};