class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // next greater element
        stack<int>st;
        vector<int>ans;
        int n = temp.size();
        map<int, int>mp;
        // 0
        // i = 1 , [1]
        // i = 2, [1,1]
        // i = 3, []
        for(int i=0; i<n; i++) {
            if(st.empty()) {
                st.push(i);
                continue;
            }
            while(!st.empty() && temp[st.top()] < temp[i] ) {
                mp[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            mp[st.top()] = 0;
            st.pop();
        }
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};