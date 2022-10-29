class Solution {
public:
    
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int,int>> t;
        
        for(int i=0;i<pt.size();i++){
            t.push_back({pt[i],gt[i]});
        }
        
        sort(t.begin(),t.end(),cmp);
        
        int s = 0;
        int ans = 1;
        
        for(int i=0;i<pt.size();i++){
            s+=t[i].first;
            ans = max(ans,s+t[i].second);
        }
        
        return ans;
    }
};