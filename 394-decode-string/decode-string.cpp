class Solution {
public:
    string decodeString(string s) {
        stack<char>stChar;
        stack<int>stInt;

        string ans = "";
        int i=0;

        while(i<s.size()) {
            if (isdigit(s[i])) {
                int num = 0;
                while(i<s.size() && isdigit(s[i])) {
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                stInt.push(num);
            }
            else if (s[i] == '[') {
                stChar.push(s[i]);
                i++;
            }else if (s[i] == ']') {
                string subAns = "";
                while(!stChar.empty() && stChar.top() != '[') {
                    subAns = stChar.top() + subAns;
                    stChar.pop();
                }
                stChar.pop(); // Remove '['
                int repeat = stInt.top();
                stInt.pop();

                string repSubAns ="";
                for (int j=0; j<repeat; j++) {
                    repSubAns += subAns;
                }

                for (char c: repSubAns) {
                    stChar.push(c);
                }
                i++;
            } else {
                stChar.push(s[i]);
                i++;
            }
        }

         while (!stChar.empty()) {
            ans = stChar.top() + ans;
            stChar.pop();
        }


        return ans;
    }
};