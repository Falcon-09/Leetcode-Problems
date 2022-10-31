class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i>0 and j>0 and mat[i-1][j-1]!=mat[i][j]) return false;
            }
        }
        
        return true;
    }
};