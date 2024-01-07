class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int j=0;
        string ans = "";
        string temp = "";
        while(j<s.length()) {
            if (s[j] == ' ') {
                reverse(temp.begin(), temp.end());
                if (temp != "") {
                    ans += temp + " ";
                }
                temp = "";
            } else {
                temp += s[j];
            }
            j++;
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        
        // int i=0;
        // string final_ans = "";
        // while(s[i] == ' ') {
        //     i++;
        // }
        // final_ans += ans.substr(i);

        // string final_final = "";
        // int k = final_ans.length()-1;
        // while(final_ans[k] == ' ') {
        //     k--;
        // }
        // final_final = final_ans.substr(0, k+1);
        if (ans[ans.size() - 1] == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};