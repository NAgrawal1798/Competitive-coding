class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
       unordered_set<int>st(nums.begin(), nums.end());

       int x=1; // starting from the first bit
       while(true) {
           if (!st.count(x)) {
               break;
           }
           x<<= 1; // find number with next bit
       }
       return x;
    }
};