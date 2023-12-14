class Solution {
public:
    string sum(string s1, string s2) {
        int i=s1.size()-1;
        int j=s2.size()-1;
        int carry=0;
        string ans = "";

        while(i >=0 || j>=0 || carry) {
            int x = i>=0 ? s1[i] - '0' : 0;
            int y = j>=0 ? s2[j] - '0' : 0;
            int sum = x+y+carry;
            carry = sum/10;
            int num = sum%10;
            ans += to_string(num);
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        vector<int> products(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + products[i + j + 1];
                products[i + j] += sum / 10;
                products[i + j + 1] = sum % 10;
            }
        }

        string result = "";
        for (int num : products) {
            if (!(result.empty() && num == 0)) {
                result += to_string(num);
            }
        }

        return result.empty() ? "0" : result;
    }
};