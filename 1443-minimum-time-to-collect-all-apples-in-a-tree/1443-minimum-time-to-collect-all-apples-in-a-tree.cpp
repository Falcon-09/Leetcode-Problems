class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> e(n);
        for(vector<int>& edge: edges) {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }

        function<int(int, int)> solve = [&](int prev, int curr) {
            int count = 0;

            for(int n: e[curr]) {
                if(n == prev) continue;
                count += solve(curr, n);
            }

            return count ? count + 2 : hasApple[curr] * 2;
        };

        return max(0, solve(-1, 0) - 2);
    }
};