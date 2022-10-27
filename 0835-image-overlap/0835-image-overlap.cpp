class Solution {
public:
    int n;
    int valid(int a, int b){
        if(a >= 0 && a < n && b >= 0 && b < n) return true;
        return false;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        int ans = 0;
        for(int i=1-n; i<n; i++){
            for(int j=1-n; j<n; j++){
                int curr = 0;
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        if(valid(k+i,l+j) && img1[k+i][l+j] && img2[k][l]) curr++;
                    }
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};