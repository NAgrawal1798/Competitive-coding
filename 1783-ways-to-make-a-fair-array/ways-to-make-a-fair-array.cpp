class Solution {
public:
    // soltion can be done in O(n)
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int ev = 0;
        int od = 0;

        vector<int>even(n);
        vector<int>odd(n);

        for (int i=0; i<n; i++) {
            if (i%2 == 0) {
                ev +=nums[i];
            } else {
                od += nums[i];
            }

            even[i] = ev;
            odd[i] = od;
        }

        for (int i=0; i<n; i++) {
            if (i==0) {
                int nos = even[n-1] - even[0];
                int nes = odd[n-1] - odd[0];
                if (nos == nes) {
                    ans++;
                }
                continue;
            }
            int nes = even[i-1] + odd[n-1] -  odd[i];
            int nos = odd[i-1] + even[n-1] - even[i];
            if (nos == nes) {
                ans++;
            }
        }

        return ans;
    }
};