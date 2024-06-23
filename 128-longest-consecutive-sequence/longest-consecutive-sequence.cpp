class Solution {
public:
    // unordered_set
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num: nums) {
            st.insert(num);
        }

        int ans = 0;
        for(int num: nums) {
            if (st.find(num - 1) == st.end()) {
                int currNum = num;
                int currSeq = 1;
                while(st.find(currNum + 1) != st.end()) {
                    currNum++;
                    currSeq++;
                }
                ans = max(ans, currSeq);
            }
        }

        return ans;
    }
};