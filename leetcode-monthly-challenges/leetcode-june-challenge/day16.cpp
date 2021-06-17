class Solution
{
public:
    void generate(vector<string> &ans, string curr, int left, int right, int n)
    {
        // cout<<1<<endl;
        if (left == n && right == n)
        {
            ans.push_back(curr);
            return;
        }

        if (left == n)
        {
            while (right < n)
            {
                curr += ")";
                right++;
            }
            ans.push_back(curr);
            return;
        }
        else if (left == right)
        {
            generate(ans, curr + "(", left + 1, right, n);
        }
        else
        {
            generate(ans, curr + "(", left + 1, right, n);
            generate(ans, curr + ")", left, right + 1, n);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string curr = "(";
        int left = 1, right = 0;
        generate(ans, curr, left, right, n);
        return ans;
    }
};