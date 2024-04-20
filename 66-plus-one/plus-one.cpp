class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        reverse(digits.begin(), digits.end());
        int n = digits.size();
        vector<int>ans(n, 0);
        int carry = 1;
        for(int i=0; i<n; i++) {
            int sum = digits[i];
            if(carry == 1) {
                sum += 1;
            }
            if(sum >9) {
                ans[i] = 0;
                carry = 1;
            } else {
                ans[i] = sum;
                carry = 0;
            }
        }
        if(carry == 1) {
            ans.push_back(1);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};