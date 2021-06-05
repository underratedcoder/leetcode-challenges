class Solution
{
public:
    int ans;

    int openLock(vector<string> &deadends, string target)
    {
        ans = INT_MAX;
        set<string> dead;
        for (int i = 0; i < deadends.size(); i++)
        {
            dead.insert(deadends[i]);
        }
        if (dead.find("0000") != dead.end() || dead.find(target) != dead.end())
            return -1;
        queue<string> q;
        q.push(target);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size > 0)
            {
                string current = q.front();
                q.pop();
                // cout<<current<<endl;
                if (dead.find(current) != dead.end())
                {
                    size--;
                    continue;
                }
                if (current == "0000")
                    return level;
                for (int i = 0; i < 4; i++)
                {
                    string down = current, up = current;
                    down[i] = (down[i] == '0' ? '9' : down[i] - 1);
                    up[i] = (up[i] == '9' ? '0' : up[i] + 1);
                    if (dead.find(down) == dead.end())
                    {
                        q.push(down);
                        // cout<<down<<endl;
                    }
                    if (dead.find(up) == dead.end())
                    {
                        q.push(up);
                        // cout<<up<<endl;
                    }
                }
                dead.insert(current);
                size--;
            }
            level++;
        }
        return -1;
    }
};