class Solution {
public:
    vector<int> answerQueries(vector<int>& arr, vector<int>& q) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> ans;
        
        for(int i=0;i<q.size();i++){
            int k = q[i];
            int len = 0,s = 0;
            for(int j=0;j<n;j++){
                if(k>s){
                    s+=arr[j];
                    len++;
                    if(k<s) len--;
                }
            }
            
            ans.push_back(len);
        }
        
        return ans;
    }
};