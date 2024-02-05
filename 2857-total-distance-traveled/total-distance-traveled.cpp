class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank) {
            if(mainTank >= 5) {
                mainTank = mainTank - 5;
                ans += 50;
                if (additionalTank) {
                    mainTank += 1;
                    additionalTank--;
                }
            } else {
                mainTank--;
                ans += 10;
            }   
        }
        return ans;
    }
};