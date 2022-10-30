class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
        
        int vis[n][m][k+1];
        
        memset(vis,0,sizeof(vis));
        
        queue<vector<int>> q;
        q.push({0,0,k});
        
        int ans = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto p = q.front();
                q.pop();
                if(p[0]==n-1 and p[1]==m-1) return ans;
                for(int d=0;d<4;d++){
                    int i = p[0]+dir[d][0];
                    int j = p[1]+dir[d][1];
                    int obs = p[2];
                    
                    if(i>=0 and j>=0 and i<n and j<m){
                        if(mat[i][j]==0 and !vis[i][j][obs]){
                            q.push({i,j,obs});
                            vis[i][j][obs] = 1;
                        }else if(mat[i][j]==1 and obs>0 and !vis[i][j][obs-1]){
                            q.push({i,j,obs-1});
                            vis[i][j][obs-1] = 1;
                        }
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};