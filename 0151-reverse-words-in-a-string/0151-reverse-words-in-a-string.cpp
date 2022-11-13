class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        
        vector<string> v;
        
        string t;
        
        while (ss >> t)
            v.push_back(t);
        
        string res;
        
        for (int i = v.size()-1; i > -1; i--)
            res += v[i] + " ";
        
        res.pop_back();
        
        return res;
    }
};