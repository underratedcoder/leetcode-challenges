class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0, j = 0, one = 0, zero = 0, n = nums.size(), ans = 0;
        while (i < n && j < n)
        {
            while (j < n && (zero < k || (zero == k && nums[j] == 1)))
            {
                if (nums[j] == 0)
                {
                    zero++;
                }
                else
                {
                    one++;
                }
                j++;
                ans = max(ans, one + zero);
            }
            while (zero >= k && i <= j)
            {
                if (nums[i] == 0)
                {
                    zero--;
                }
                else
                {
                    one--;
                }
                i++;
            }
        }

        return ans;
    }
};