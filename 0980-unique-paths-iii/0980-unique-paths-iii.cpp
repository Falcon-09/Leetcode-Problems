class Solution {
public:
    
    int f(int i,int j,vector<vector<int>> &mat,int z){
        if(i<0 or j<0 or i>=mat.size() or j>=mat[0].size() or mat[i][j]==-1) return 0;
        
        if(mat[i][j]==2){
            if(z==0) return 1;
            return 0;
        }
        mat[i][j] = -1;
        int ans = 0;
        
        ans+=f(i-1,j,mat,z-1);
        ans+=f(i+1,j,mat,z-1);
        ans+=f(i,j-1,mat,z-1);
        ans+=f(i,j+1,mat,z-1);
        
        mat[i][j] = 0;
        
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int x,y,z=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) {
                    x = i;
                    y = j;
                }else if(mat[i][j]==0) z++;
            }
        }
        
        return f(x,y,mat,z+1);
    }
};