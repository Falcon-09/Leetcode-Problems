class Solution {
public:
    int nearestExit(vector<vector<char>>& mat, vector<int>& e) {
        queue<pair<int,int>> q;
        if(mat.size()==1 and mat[0].size()==1) return -1;
        q.push({e[0],e[1]});
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int ans = 0;
        mat[e[0]][e[1]] = '+';
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                
                q.pop();
                
                for(int d=0;d<4;d++){
                    int nx = r+dir[d][0];
                    int ny = c+dir[d][1];
                    
                    if(nx>=0 and ny>=0 and nx<mat.size() and ny<mat[0].size() and mat[nx][ny]!='+'){
                        mat[nx][ny] = '+';
                        if(nx==0 or nx==mat.size()-1) return ans+1;
                        if(ny==0 or ny==mat[0].size()-1) return ans+1;
                        else q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};