class Solution {
public:
    int countOdds(int low, int high) {
        return (low%2==0 and high%2==0)?(high-low)/2:(high-low)/2+1;
    }
};