class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        bool f = false;
        for(int i=0;i<s.size();i++){
            while(ans.size()>0 and ans.back()==s[i]){
                ans.pop_back();
                f = true;
            }
            if(f){
                f = false;
                continue;
            }
            ans+=s[i];
        }
        
        return ans;
    }
};