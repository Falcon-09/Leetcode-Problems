class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {
            long long int csum = 0;
            long long int tsum = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                tsum += nums[i];
            }

            long long int ans = INT_MAX;
            int res;
            for (int i = 0; i < n; i++)
            {
                csum += nums[i];
                tsum -= nums[i];
                long long int diff1 = csum / (i + 1);
                long long int diff2;
                if (i == n - 1)
                {
                    diff2 = 0;
                }
                else
                {
                    diff2 = tsum / (n - i - 1);
                }
                long long int curr = abs(diff1 - diff2);
                if (curr < ans)
                {
                    res = i;
                    ans = curr;
                }
            }

            return res;
        }
};