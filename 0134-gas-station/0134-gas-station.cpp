class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tc = 0;
        
        for(int i=0;i<gas.size();i++) {
            tc+=gas[i]-cost[i];
        }
        
        if(tc<0) return -1;
        
        tc = 0;
        int ans = 0;
        
        for(int i=0;i<gas.size();i++){
            tc+=gas[i]-cost[i];
            
            if(tc<0) {
                ans = i+1;
                tc = 0;
            }
        }
        
        return ans;
    }
};