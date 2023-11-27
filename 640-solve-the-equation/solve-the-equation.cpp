class Solution {
public:
    // count +ve x and -ve x
    // find the sum of integers
    // if x = x then infinite solutions
    // if integer value is equal and 
    int findIndex (string equation, char s) {
        for (int i=0; i<equation.size(); i++) {
            if (equation[i] == s) {
                return i;
            }
        }
        return 0;
    }
    pair<int,int> findNumOfX(string s1) {
        int coefficient = 0;
        int constant = 0;
        int num = 0;
        int sign = 1;

        for (int i=0; i<s1.length(); i++) {
            const char c = s1[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                constant += sign * num;
                sign = c == '+' ? 1 : -1;
                num = 0;
            } else {
                if ( i > 0 && num == 0 && s1[i-1] == '0') {
                    continue;
                }
                coefficient += num == 0 ? sign : sign * num;
                num=0;
            }
        }
        
        return {coefficient, constant + sign * num};
    }
    string solveEquation(string equation) {
        int i = findIndex(equation, '=');
        string s1 = equation.substr(0, i);
        string s2 = equation.substr(i+1);

        pair<int,int> num1 = findNumOfX(s1);
        pair<int,int> num2 = findNumOfX(s2);

        int value1 = num1.second;
        int value2 = num2.second;
        int x1 = num1.first;
        int x2 = num2.first;

        cout<<num1.first<<" "<<num1.second<<endl;
        cout<<num2.first<<" "<<num2.second<<endl;
        const int coefficient = x1 - x2;
        const int constant = value2 - value1;

        if (coefficient == 0 && constant == 0)
        return "Infinite solutions";
        if (coefficient == 0 && constant != 0)
        return "No solution";
        return "x=" + to_string(constant / coefficient);
    }
};