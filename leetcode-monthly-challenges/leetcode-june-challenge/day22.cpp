class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        vector<vector<int>> alphas(26);
        for (int i = 0; i < size(s); i++)
        {
            alphas[s[i] - 'a'].push_back(i);
        }
        for (auto &word : words)
        {
            int fnd = 1, prev = -1;
            for (int i = 0; i < size(word); i++)
            {
                auto &v = alphas[word[i] - 'a'];
                auto it = upper_bound(begin(v), end(v), prev);
                if (it == end(v))
                {
                    fnd = 0;
                    break;
                }
                else
                {
                    prev = *it;
                }
            }
            ans += fnd;
        }
        return ans;
    }
};