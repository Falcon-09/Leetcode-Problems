class Solution {
public:
    int getIdx(string &curr)
    {
        for(int i=0;i<curr.size();i++)
        {
            if(curr[i] == '0')
                return i;
        }
        return 0;
    }
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string done = "123450"; 
        string curr;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                curr.push_back(board[i][j] + '0');
            }
        }
        vector<vector<int>> choices = { {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4} };
       
        queue<string> q;
        set<string> visited;
        q.push(curr);
        visited.insert(curr);
        int level = 0;
        
        while(q.size())
        {
            int sz = q.size();
            while(sz--)
            {
                string cur = q.front();
                q.pop();
                
                if(cur == done)
                    return level; 
                
                int idx = getIdx(cur);
            
                for(int i=0;i<choices[idx].size();i++)
                {
                    int j = choices[idx][i];
                    swap(cur[idx],cur[j]);
                    string temp = cur; 
                    swap(cur[idx],cur[j]);
                    if(visited.find(temp)==visited.end()) 
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};