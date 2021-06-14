class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size(), ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({boxTypes[i][1], boxTypes[i][0]});
        }
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n; i++)
        {
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            if (truckSize >= v[i].second)
            {
                ans += v[i].first * v[i].second;
                truckSize -= v[i].second;
            }
            else
            {
                ans += v[i].first * truckSize;
                truckSize = 0;
                break;
            }
        }
        return ans;
    }
};