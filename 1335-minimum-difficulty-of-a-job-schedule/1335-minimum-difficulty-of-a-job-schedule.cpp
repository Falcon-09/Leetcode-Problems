class Solution
{
    public:

        int solve(vector<int> &arr, int index, int d, vector<vector< int>> &dp)
        {

            if (index >= arr.size())
                return 1e7;

            if (d == 1)
            {
                int temp = 0;
                for (int i = index; i < arr.size(); i++)
                {
                    temp = max(temp, arr[i]);
                }

                return temp;
            }

            if (dp[index][d] != -1)
                return dp[index][d];

            int res = INT_MAX;
            int curr = 0;

            for (int i = index; i < arr.size(); i++)
            {
                curr = max(curr, arr[i]);
                res = min(res, curr + solve(arr, i + 1, d - 1, dp));
            }

            return dp[index][d] = res;
        }

    int minDifficulty(vector<int> &arr, int d)
    {
        if (arr.size() < d)
            return -1;

        vector<vector < int>> dp(arr.size(), vector<int> (d + 1, -1));

        int res = solve(arr, 0, d, dp);

        return res;
    }
};