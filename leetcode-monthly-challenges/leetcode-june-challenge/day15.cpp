class Solution
{
public:
    bool checkSquare(vector<int> &matchsticks, vector<int> &vis, int idx, int n, int currSum, int targetSum, int sides)
    {
        if (idx == n && currSum < targetSum)
            return false;
        if (currSum == targetSum)
        {
            if (sides == 1)
                return true;
            else
                return checkSquare(matchsticks, vis, 0, n, 0, targetSum, sides - 1);
        }
        for (int i = idx; i < n; i++)
        {
            if (vis[i] == 0 && currSum + matchsticks[i] <= targetSum)
            {
                vis[i] = 1;
                if (checkSquare(matchsticks, vis, i + 1, n, currSum + matchsticks[i], targetSum, sides))
                    return true;
                vis[i] = 0;
            }
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++)
        {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0 || matchsticks.size() < 4)
            return false;
        int n = matchsticks.size(), sides = 4, currSum = 0, targetSum = sum / 4, idx = 0;
        vector<int> vis(n, 0);
        return checkSquare(matchsticks, vis, idx, n, currSum, targetSum, sides);
    }
};