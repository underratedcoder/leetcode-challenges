class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &arr, int l, int r)
    {
        int count = 0, n = arr.size();
        vector<int> right(n, n);
        stack<int> s;
        s.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                right[i] = s.top();
            }
            s.push(i);
        }
        vector<int> left(n, -1);
        stack<int> p;
        p.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!p.empty() && arr[p.top()] < arr[i])
            {
                p.pop();
            }
            if (!p.empty())
            {
                left[i] = p.top();
            }
            p.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= l && arr[i] <= r)
            {
                count += (i - left[i]) * (right[i] - i);
            }
        }
        return count;
    }
};
