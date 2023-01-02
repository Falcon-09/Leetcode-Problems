class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n==1) return true;
        bool flag = false;
        int cnt = 0;
        
        for(int i=1;i<n;i++){
            if(isupper(word[i])) flag = true,cnt++;
        }
        
        if(cnt==n-1) {
            if(isupper(word[0])) return true;
            return false;
        }
        if(flag) return false;
        
        return true;
    }
};