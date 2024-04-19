class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // iterate over this array
        // find the minimum and maxiumum element
        // usually store the indices then find the gap 
        int maxi = nums[0];
        int mini = nums[0];
        int min_index = 0;
        int max_index = 0;

        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(maxi > nums[i]) {
                maxi = nums[i];
                max_index = i;
            }
            if(mini < nums[i]) {
                mini = nums[i];
                min_index = i;
            }
        }
        // three possiblities of answer
        int num1 = max(min_index + 1, max_index + 1);
        int num2 = max( n - min_index, n - max_index);
        int num3 = min(min_index + 1, max_index + 1) + min(n - min_index, n - max_index);

        return min({num1, num2, num3});
    }
};