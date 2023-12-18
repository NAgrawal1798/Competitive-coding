class Solution {
public:
    // greatest common divisor
    int gcd(int a, int b) {
        if(a==0) {
            return b;
        }
        return gcd(b%a, a);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int  largest = nums[nums.size() -1];

        return gcd(largest, smallest);

    }
};