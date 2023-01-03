class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size();
        int m = s[0].size();
        int cnt = 0,j = 0;
        
        for(int i=0;i<m;i++){
            char pre = s[0][i];
            
            for(int j=1;j<n;j++){
                if(s[j][i]<pre){
                    cnt++;
                    break;
                } else{
                    pre = s[j][i];
                }
            }
        }
        
        return cnt;
    }
};