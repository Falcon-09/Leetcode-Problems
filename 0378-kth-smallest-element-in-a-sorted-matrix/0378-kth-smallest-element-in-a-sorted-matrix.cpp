class Solution {
public:
    
    int ok(vector<vector<int>> &mat,int k){
        int cnt=0,n=mat.size(),i=n-1,j=0;
        while(i>=0 and j<n){
            if(mat[i][j]>k) i--;
            else {
                cnt = cnt+i+1;
                j++;
            }
        }
        
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        int lo = mat[0][0];
        int hi = mat[n-1][n-1];
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int cnt = ok(mat,mid);
            if(cnt<k) lo=mid+1;
            else hi=mid-1;
        }
        
        return lo;
    }
};