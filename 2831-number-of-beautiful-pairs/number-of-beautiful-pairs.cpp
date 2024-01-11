class Solution {
public:

    int gcd(int a, int b) {
        if (a==0) {
            return b;
        }
        return gcd(b%a, a);
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        set<pair<int,int>>st;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int first_digit = to_string(nums[i])[0] - '0';
                int last_digit = nums[j] % 10;

                if (gcd(first_digit, last_digit) == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};