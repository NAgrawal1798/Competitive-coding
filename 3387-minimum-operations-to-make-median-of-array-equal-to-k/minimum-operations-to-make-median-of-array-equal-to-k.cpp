class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int mid = n/2;

        int midEle = nums[mid];

        if(midEle == k) {
            return 0;
        }

        long long ans = 0;
        if(midEle > k) {
            ans = nums[mid] - k;
            int i=mid-1;
            while(i>=0) {
                if(nums[i] > k) {
                    ans += nums[i] - k;
                } else {
                    break;
                }
                i--;
            }
        } else {
            ans = k - nums[mid];
            int i=mid+1;
            while(i<n) {
                if(nums[i] < k) {
                    ans += k - nums[i];
                } else {
                    break;
                }
                i++;
            }
        }

        return ans;

    }
};