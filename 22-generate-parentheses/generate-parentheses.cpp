class Solution {
public:
    vector <string> ans;
    string current;

    void solve (int index, int delta, int len)
    {
        if (delta < 0)
        {
            return;
        }

        if (index == len)
        {
            if (delta == 0)
            {
                ans.push_back (current);
            }

            return;
        }

        current.push_back ('(');
        solve (index + 1, delta + 1, len);
        current.pop_back();

        current.push_back (')');
        solve (index + 1, delta - 1, len);
        current.pop_back();
    }

    vector <string> generateParenthesis (int n)
    {
        solve (0, 0, n + n);

        return ans;
    }
};