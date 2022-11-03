class Solution {
public:
    
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        int ans = 0 , flag = 0;
        for(auto x : words){
            m[x]++;
        }
        
        for(auto x : m){
            string rev = x.first;
            reverse(rev.begin(),rev.end());
            if(m[rev] != 0){
                if(rev != x.first){
                    ans += 4*min(m[rev],m[x.first]);
                }
                else{
                    ans += 4*(m[x.first]/2);
                    if(m[x.first]%2){
                        flag = 1;
                    }
                }
            }
            m.erase(rev);
            m.erase(x.first);
        }
        return ans+flag*2;
    }
};