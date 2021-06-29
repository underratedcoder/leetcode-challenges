class NumArray
{
public:
    int n;
    vector<int> nums;
    int sum_seg[1000000];

    void createSumSegmentTree(int l_index, int r_index, int pos)
    {
        if (l_index == r_index)
        {
            sum_seg[pos] = nums[l_index];
            return;
        }
        int mid = (l_index + r_index) / 2;
        createSumSegmentTree(l_index, mid, 2 * pos + 1);
        createSumSegmentTree(mid + 1, r_index, 2 * pos + 2);
        sum_seg[pos] = sum_seg[2 * pos + 1] + sum_seg[2 * pos + 2];
    }

    int sumQuery(int l_index, int r_index, int pos, int l, int r)
    {
        if (l_index > r || r_index < l)
            return 0;
        if (l_index >= l && r_index <= r)
            return sum_seg[pos];
        int mid = (l_index + r_index) / 2;
        return sumQuery(l_index, mid, 2 * pos + 1, l, r) + sumQuery(mid + 1, r_index, 2 * pos + 2, l, r);
    }

    void updateNode(int l_index, int r_index, int pos, int index, int value)
    {
        if (l_index == r_index)
        {
            if (l_index == index)
            {
                nums[index] = value;
                sum_seg[pos] = value;
            }
            return;
        }
        int mid = (l_index + r_index) / 2;
        if (index >= l_index && index <= mid)
            updateNode(l_index, mid, 2 * pos + 1, index, value);
        if (index >= mid + 1 && index <= r_index)
            updateNode(mid + 1, r_index, 2 * pos + 2, index, value);
        sum_seg[pos] = sum_seg[2 * pos + 1] + sum_seg[2 * pos + 2];
    }

    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        this->n = nums.size();
        createSumSegmentTree(0, n - 1, 0);
    }

    void update(int index, int val)
    {
        updateNode(0, n - 1, 0, index, val);
    }

    int sumRange(int left, int right)
    {
        return sumQuery(0, n - 1, 0, left, right);
    }
};