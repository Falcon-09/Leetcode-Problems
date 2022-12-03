class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto x:s){
            mp[x]++;
        }
        
        string ans;
        
        vector<pair<int,char>> v;
        
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        
        sort(v.rbegin(),v.rend());
        
        for(auto x:v){
            while(x.first--){
                ans+=x.second;
            }
        }
        
        return ans;
    }
};