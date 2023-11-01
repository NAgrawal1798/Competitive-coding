class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // Use a pair to store the character and its count.
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top().first == s[i]) {
                st.top().second++; // Increment the count for the current character.
                if (st.top().second == k) {
                    st.pop(); // If the count reaches k, remove the character from the stack.
                }
            } else {
                st.push({s[i], 1}); // Push the current character with count 1.
            }
        }

        string ans;
        while (!st.empty()) {
            int count = st.top().second;
            char c = st.top().first;
            st.pop();
            while (count--) {
                ans += c;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
