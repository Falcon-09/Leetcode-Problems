class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(isupper(s[i])){
                if(ans.back()==tolower(s[i])){
                    ans.pop_back();
                    continue;
                }
            }else if(islower(s[i])){
                if(ans.back()==toupper(s[i])){
                    ans.pop_back();
                    continue;
                }
            }
            ans+=s[i];
        }
        
        return ans;
    }
};