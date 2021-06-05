class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        int hzLen = horizontalCuts.size(), vtLen = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long int maxHz = max(horizontalCuts[0], h - horizontalCuts[hzLen - 1]);
        long int maxVt = max(verticalCuts[0], w - verticalCuts[vtLen - 1]);
        for (int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            maxHz = max(maxHz, (long int)horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for (int i = 0; i < verticalCuts.size() - 1; i++)
        {
            maxVt = max(maxVt, (long int)verticalCuts[i + 1] - verticalCuts[i]);
        }
        return maxHz * maxVt % 1000000007;
    }
};