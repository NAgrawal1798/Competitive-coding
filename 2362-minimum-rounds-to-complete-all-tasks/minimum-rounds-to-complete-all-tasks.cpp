class Solution {
public:
    // Use map
    int minimumRounds(vector<int>& tasks) {
        std::map<int, int> mp;

        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }

        int ans = 0;
        for (auto it : mp) {
           if (it.second < 2) {
               return -1;
           }
           ans += ceil(it.second/3.0);
        }
        return ans;
    }
};