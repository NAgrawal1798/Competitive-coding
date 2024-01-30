class Solution {
public:
   
    void recursiveCall(int i, string sumPath, long sum, long prev, string num, int target, vector<string>&result) {

        // If we have reached the end of 'num'
        if(i==num.size()) {
            if(sum == target) {
                result.push_back(sumPath);
            }
            return;
        }

        for(int j=i; j<num.size(); j++) {

            // Avoid leading zeroes in the number
            if(j>i && num[i] == '0') {
                break;
            }
            // convert the substring to a long number
            long number = stol(num.substr(i,j-i+1));

            // Temporary substring representing the path we have traversed so  far
            string tempPath = num.substr(i, j-i+1);

            if(i==0) {
                recursiveCall(j+1, tempPath, number, number, num, target, result);
            } else {
                // Addition operation
                recursiveCall(j+1, sumPath + '+' + tempPath, sum + number, number, num, target, result);

                //Substraction operation
                recursiveCall(j+1, sumPath + '-' + tempPath, sum-number, -number, num, target, result);

                //Multiplication operation
                recursiveCall(j+1, sumPath + '*' + tempPath, sum - prev + (prev*number), prev*number, num, target, result);
                // This is done to follow the bodmas rule.
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>result;
        recursiveCall(0, "", 0, 0, num, target, result);
        return result;
    }
};