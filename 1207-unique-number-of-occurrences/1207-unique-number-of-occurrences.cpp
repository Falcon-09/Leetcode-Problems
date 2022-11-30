class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto x:arr) mp[x]++;
        
        for(auto x:mp){
            if(s.find(x.second)!=s.end()) return false;
            s.insert(x.second);
        }
        
        return true;
    }
};