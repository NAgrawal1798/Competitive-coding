class Solution {
public:
    void helper(string digits, vector<string>& ans, string temp, vector<string> phone_map) {
        if(digits.empty()) {
            ans.push_back(temp);
        } else {
            string letters = phone_map[digits[0] - '2'];
            for(char letter: letters) {
                helper(digits.substr(1), ans, temp + letter, phone_map);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
       // Do backtracking
       vector<string>phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
       vector<string>ans;
       helper(digits, ans, "", phone_map);
       return ans;
    }
};