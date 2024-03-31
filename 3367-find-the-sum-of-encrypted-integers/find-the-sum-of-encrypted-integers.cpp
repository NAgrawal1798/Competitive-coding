class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            string num = to_string(nums[i]);
            int maxi = INT_MIN;
            for(int j=0; j<num.size(); j++) {
                maxi = max(num[j] - '0', maxi);
            }

            for(int j=0; j<num.size(); j++) {
                num[j] = maxi + '0';
            }

            ans += stoi(num);
        }

        return ans;
    }
};