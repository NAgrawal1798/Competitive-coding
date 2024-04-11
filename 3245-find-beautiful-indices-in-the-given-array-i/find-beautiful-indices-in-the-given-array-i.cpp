class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int S = s.size();
        int A = a.size();
        int B = b.size();
        vector<int> ai;
        vector<int> bi;
        int i = 0;

        // Populate vectors ai and bi with indices of occurrences of substrings a and b
        while (i < S - A + 1 || i < S - B + 1)
        {
            if (i < S - A + 1 && s.substr(i, A) == a)
            {
                ai.push_back(i);
            }
            if (i < S - B + 1 && s.substr(i, B) == b)
            {
                bi.push_back(i);
            }
            i++;
        }
        
        int n1 = ai.size();
        int n2 = bi.size();
        vector<int> ans;
        i = 0;
        int j = 0;

        // Find beautiful indices based on the defined criteria
        while (i < n1 && j < n2)
        {
            if (abs(ai[i] - bi[j]) <= k)
            {
                ans.push_back(ai[i]);
                i++;
            }
            else if (ai[i] < bi[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        return ans;
    }
};