class Solution {
public:
    bool isSpecialChar(char c) {
        string special = "!@#$%^&*()-+";
        for (int i=0; i<special.size(); i++) {
            if (c == special[i]) {
                return true;
            }
        }
        return false;
    }

    bool strongPasswordCheckerII(string password) {
        // At least 8 characters
        if (password.size() < 8) {
            return false;
        }
        bool specialChar = false;
        bool isUpperCaseChar = false;
        bool isLowerCaseChar = false;
        bool isDigit = false;

        for(int i=0; i<password.size(); i++) {
            if (isSpecialChar(password[i])) {
                specialChar = true;
            }
            if (password[i]  >= 'A' && password[i] <= 'Z') {
                isUpperCaseChar = true;
            }
            if (password[i] >= 'a' && password[i] <= 'z') {
                isLowerCaseChar = true;
            }
            if (isdigit(password[i])) {
                isDigit = true;
            }
            if (i != 0) {
                if (password[i] == password[i-1]) {
                    return false;
                }
            }
        }

        if (specialChar && isUpperCaseChar && isLowerCaseChar && isDigit) {
            return true;
        }
        return false;
    }
};