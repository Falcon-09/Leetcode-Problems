class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j] && f(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool f(vector<vector<char>> &b,int i,int j,string w,int pos){
        if(pos==w.size()){
            return true;
        }
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size()) return false;
        if(w[pos]!=b[i][j]) return false;
        char t=b[i][j];
        b[i][j]='.';
        bool ans = false;
        ans|=f(b,i+1,j,w,pos+1);
        ans|=f(b,i-1,j,w,pos+1);
        ans|=f(b,i,j+1,w,pos+1);
        ans|=f(b,i,j-1,w,pos+1);
     
        b[i][j]=t;
        return ans;
    }
    
};