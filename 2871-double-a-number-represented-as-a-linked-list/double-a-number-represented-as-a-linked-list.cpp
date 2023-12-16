/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
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
    ListNode* doubleIt(ListNode* head) {
        string s = "";
        while(head) {
            // cout<<head->val<<endl;
            s += to_string(head->val);
            head = head->next;
        }

        string res = multiply(s, "2");

        ListNode* result = new ListNode();
        ListNode* ans = result;
        for (int i=0; i<res.size(); i++) {
            result->next = new ListNode(res[i] - '0');
            result = result->next;
        }

        return ans->next;

    }
};