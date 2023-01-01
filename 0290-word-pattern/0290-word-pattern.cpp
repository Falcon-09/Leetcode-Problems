class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        
        vector<string> v;
        
        stringstream ss(s);
        string t;
        
        while(getline(ss,t,' ')){
            v.push_back(t);
        }
        
        if(p.size()!=v.size()) return false;
        
        for(int i=0;i<p.size();i++){
            if(!mp1.count(p[i]) and !mp2.count(v[i])){
                mp1[p[i]] = v[i];
                mp2[v[i]] = p[i];
            }else{
                if(mp1[p[i]]!=v[i] or mp2[v[i]]!=p[i]) return false; 
            }
        }
        
        return true;
    }
};