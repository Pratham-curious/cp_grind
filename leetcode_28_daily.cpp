class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        int odd = 0, eve = 0, sum = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum & 1)
            {
                odd++;
                ans = (ans + eve + 1) % mod;
            }
            else
            {
                eve++;
                A ans = (ans + odd) % mod;
            }
        }
        return ans;
    }
};