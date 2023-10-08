class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>mp;

        int max_ans = 0;
        int size = nums.size();

        for (int i=0; i<size; i++) {
            mp[nums[i]]++;

            if (mp.find(nums[i] - 1) != mp.end()) {
                cout<<nums[i]<<" "<<mp[nums[i]]<<endl;
                max_ans = max(max_ans, mp[nums[i]] + mp[nums[i] - 1]);
            }
            if (mp.find(nums[i] + 1) != mp.end()) {
                                cout<<nums[i]<<" "<<mp[nums[i]]<<endl;

                max_ans = max(max_ans, mp[nums[i]] + mp[nums[i] + 1]);
            }
            // if (mp.find(nums[i] - 1) != mp.end()) {
            //     max_ans = max(max_ans, mp[nums[i]] + mp[abs(nums[i] - 1)]);
            // }
        }

        return max_ans;
    }
};