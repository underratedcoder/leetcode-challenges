class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_set<char> first, sec;
        unordered_map<char, char> mappings;
        int n = s.length(), m = t.length();
        if (n != m)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (first.find(s[i]) == first.end() && sec.find(t[i]) == sec.end())
            {
                mappings[s[i]] = t[i];
                first.insert(s[i]);
                sec.insert(t[i]);
            }
            else if (first.find(s[i]) != first.end() && sec.find(t[i]) != sec.end() && mappings[s[i]] == t[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};