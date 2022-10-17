class Solution {
public:
    int countTime(string time) {
        int ways = 1;
        int f = 0;
        if(time[0]=='?'){
            if(time[1]=='?') ways*=24,f=1;
            else if(time[1]<='3') ways*=3;
            else ways*=2;
        }
        
        if(time[1]=='?' and !f) {
            if(time[0]=='2') ways*=4;
            else ways*=10;
        }
        
        if(time[3]=='?') ways*=6;
        
        if(time[4]=='?') ways*=10;
        
        return ways;
    }
};