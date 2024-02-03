class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int c=0;
        int min_ = *min_element(nums.begin(), nums.end());
        for (int n : nums) {
            c+= (n==min_);
        }
        bool flag=false;
        for(int n: nums) {
            if(n%min_) {
                flag=true;
            }
        }

        if(flag) {
            return 1;
        }
        return (c+1)/2;
    }
};