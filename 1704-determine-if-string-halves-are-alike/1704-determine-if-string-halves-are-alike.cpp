class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        vector<int> l(n,0),r(n,0);
        l[0] = v.count(s[0])?1:0;
        r[n-1] = v.count(s[n-1])?1:0;
        for(int i=1;i<n;i++){
            if(v.find(s[i])!=v.end()){
                l[i] = l[i-1]+1;
            }else{
                l[i] = l[i-1];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(v.find(s[i])!=v.end()){
                r[i] = r[i+1]+1;
            }else{
                r[i] = r[i+1];
            }
        }
       
        if(l[n/2-1]==r[n/2]) return true;
        return false;
    }
};