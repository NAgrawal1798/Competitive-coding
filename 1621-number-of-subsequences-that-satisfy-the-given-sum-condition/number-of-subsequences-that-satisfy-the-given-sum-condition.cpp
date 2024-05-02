#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int mod = 1e9 + 7; // Define modulo value to avoid overflow

        // Precompute powers of 2
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        int i = 0, j = n - 1;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                // All subsequences formed by combining nums[i] with nums[i+1], ..., nums[j] are valid
                ans = (ans + pow2[j - i]) % mod;
                i++;
            } else {
                // If nums[i] + nums[j] > target, decrease j
                j--;
            }
        }

        return ans;
    }
};
