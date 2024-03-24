class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<int>s;
        int i=0;
        int j=n-1;

        while(i<j) {
            int sum = nums[i] + nums[j];
            i++;
            j--;
            s.insert(sum);
        }

        return s.size();
        
    }
};