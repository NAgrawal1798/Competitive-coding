class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;

        int extraValue = -1;
        int carry = 0;
        
        while(n--) {
            if (digits[n] == 9) {
                ans.push_back(0);
                carry = 1;
            } else {
                break;
            }
        }
        cout<<n<<endl;

        if (n == -1){
            ans.push_back(1);
        } else {
            ans.push_back(digits[n] + 1);
            n--;
            for (int k=n; k>=0; k--) {
                ans.push_back(digits[k]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};