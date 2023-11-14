class Solution {
public:\
    // DP solution
    // dp[postion][numOfMoves]

    //  int helper(int currentPosition, int target, int steps) {
    //     if (currentPosition == target) {
    //         return steps;
    //     }
    //     if (currentPosition > target) {
    //         return INT_MAX;
    //     }

    //     // Move right
    //     int rightSteps = helper(currentPosition + steps + 1, target, steps + 1);

    //     // Move left
    //     int leftSteps = helper(currentPosition - steps - 1, target, steps + 1);

    //     return std::min(rightSteps, leftSteps);
    // }
    int reachNumber(int target) {
        target = abs(target);
        int sum=0;
        int k=0;
        while(sum <target) {
            k++;
            sum +=k;
        }

        return (sum-target)%2 == 0 ? k : k%2 == 0 ? k+1 : k+2;
    }
};