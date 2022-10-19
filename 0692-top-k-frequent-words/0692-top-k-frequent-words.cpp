class comp{
public:
    bool operator()(pair<int,string> p1, pair<int,string> p2){
        return (p1.first<p2.first)||(p1.first==p2.first&&p1.second>p2.second);
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string num:words){
            mp[num]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        for(auto num:mp){
            pq.push({num.second,num.first});
        }
        vector<string> ans;
        while(k--){
            auto num=pq.top();
            pq.pop();
            ans.push_back(num.second);
        }
        return ans;
    }
};