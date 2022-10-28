class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        unordered_map<string,vector<string>> mp;
        
        vector<vector<string>> ans;
        
        for(auto s:strs){
            string t = s;
            sort(s.begin(),s.end());
            mp[s].push_back(t);
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};