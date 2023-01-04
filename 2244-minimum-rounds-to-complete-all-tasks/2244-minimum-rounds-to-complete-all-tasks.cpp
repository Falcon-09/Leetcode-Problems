class Solution {
public:
    int minimumRounds(vector<int>& tsk) {
        int n = tsk.size();
        
        map<int,int> mp;
        
        for(auto x:tsk) mp[x]++;
        
        int cnt = 0;
        
        for(auto x:mp){
            if(x.second==1) return -1;
            if(x.second%3==0) {
                cnt+=x.second/3;
            }else {
                cnt+=x.second/3 + 1;
            }
        }
        
        return cnt;
    }
};