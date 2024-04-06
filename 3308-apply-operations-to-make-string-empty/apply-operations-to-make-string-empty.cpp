class Solution {
public:
    string lastNonEmptyString(string s) {
        // brute force ----- succefully compiled

        // while(!s.empty()) {
        //     set<char>st;

        //     string temp = "";
        //     int n = s.length();
        //     for(int i=0; i<n; i++) {
        //         if(st.count(s[i]) > 0) {
        //             temp += s[i];
        //         } else {
        //             st.insert(s[i]);
        //         }
        //     }

        //     if(temp == "") {
        //         return s;
        //     }
        //     s=temp;
        // }

        // return "";

        // optimized approach
        // Thoughts that are coming in my mind
        // create one map
        map<char, int>mp;
        int n = s.length();
        for(int i=0; i<n; i++) {
            mp[s[i]]++;
        }

        int highest = 0;
        for(auto it: mp) {
            highest = max(highest, it.second);
        }

        set<char>st;
        for(auto it: mp) {
            if(highest == it.second) {
                st.insert(it.first);
            }
        }

        string ans = "";
        for(int i=n-1; i>=0; i--) {
            if(st.count(s[i]) > 0) {
                ans += s[i];
                st.erase(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};