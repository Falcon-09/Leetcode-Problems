class Solution {

    vector<int> dfs(int node, vector<int> adj[],vector<int> &visited,const string &labels, vector<int> &count) {

        visited[node] = 1;

        vector<int> freq(26);

        int label = labels[node] - 'a';
        ++freq[label];

        for(int adjN: adj[node]) {

            if(!visited[adjN]) {
                vector<int> freq_temp = dfs(adjN, adj, visited, labels, count); 
                for(int i = 0; i < 26; ++i)
                    freq[i] += freq_temp[i];
            }
        }

        count[node] = freq[label];

        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> adj[n];

        for(vector<int> &nodes : edges) {
            int u = nodes[0];
            int v = nodes[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(n), count(n);
        dfs(0, adj, visited, labels, count);
        return count;
    }
};