class Solution {
public:
    int solve(int index, string s, unordered_set<string>& st, string temp) {
        if(index == s.length()) {
            return 0;
        } else {
            temp.push_back(s[index]);
            int opt1 = -1;
            int opt2 = -1;
            // if new substring is not present in the set
            if (st.find(temp) == st.end()) {
                st.insert(temp);
                opt1 = 1 + solve(index+1, s, st, "");
                st.erase(temp);
            }
            // picked part was done , its time to not picking the char and moving to the            next           one
            opt2 = solve(index + 1, s, st, temp);
            return max(opt1, opt2);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        return solve(0, s, st, "");
    }
};