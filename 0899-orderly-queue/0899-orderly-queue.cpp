class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1) {
            sort(s.begin(),s.end());
            return s;
        } 
        
        string ans = s;
        int n = s.size();
        while(n--){
            char ch = s[0];
            s.erase(s.begin());
            s.push_back(ch);
            ans = min(ans,s);
        }
        
        return ans;
    }
};