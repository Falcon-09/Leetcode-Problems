class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) 
            return image;
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        int n=image.size(), m=image[0].size();
        if(!color){
            return vector<vector<int>>(n,vector<int>(m,0));
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        int val=image[sr][sc];
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            image[x][y]=color;
            
            for(int k=0;k<4;++k){
                int di=x+dx[k];
                int dj=y+dy[k];
                if(di>=0 and dj>=0 and di<n and dj<m and image[di][dj]==val){
                    q.push({di,dj});
                }
            }
        }
        return image;
    }
};