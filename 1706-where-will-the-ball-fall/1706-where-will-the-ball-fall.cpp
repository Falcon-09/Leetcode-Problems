class Solution {
public:
    bool valid(int m,int n,int row,int col)
    {
        if(row >=m || col>=n || row < 0 || col < 0) return false;
        return true;
    }
    
    int dfs(int row,int col,vector<vector<int>>& grid)
    {
        if(row == grid.size())
        {
            return col;
        }
        if(valid(grid.size(),grid[0].size(),row,col))
        {
            if(grid[row][col] == 1)
            {
                if(valid(grid.size(),grid[0].size(),row,col+1) && grid[row][col+1] == 1)
                {
                    return dfs(row+1,col+1,grid);
                }
            }
            else
            {
                if(valid(grid.size(),grid[0].size(),row,col-1) && grid[row][col-1] == -1)
                {
                    return dfs(row+1,col-1,grid);
                }
            }
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> ans(col);
        for(int i = 0; i < col; i++)
        {
            ans[i] = dfs(0,i,grid);
        }
        return ans;
    }
};