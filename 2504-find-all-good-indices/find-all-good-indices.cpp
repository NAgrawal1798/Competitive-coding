class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        // int n = nums.size();

    // O(1) solution

     int n = nums.size(); //calculated size
        vector<int> res; // result
        int c1 = 1, c2 = 1;
        // for (int j=2; j<k; j++)
        // {
        //     if (nums[j] >= nums[j-1])
        //         c2++;
        //     else
        //         c2 = 1;
        // }
        int i = 0;
        while (i+k<n) 
        {
            if (nums[i+k] >= nums[i+k-1])
                c2++;
            else
                c2 = 1;
            if (i>=2 && (nums[i-1] <= nums[i-2]))
                c1++;
            else
                c1 = 1;
            if (c1 >= k && c2 >=k && i >=k)
                res.push_back(i);
            i++;
        }
        return res;

    // O(n) Solution
        // vector<int>left(n,0);
        // vector<int>right(n,0);
        // vector<int>ans;

        // for (int i=1; i<n; i++) {
        //     if (nums[i] <= nums[i-1]) {
        //         left[i] = left[i-1] + 1;
        //     }
        // }

        // for (int i=n-2; i>=0; i--) {
        //     if (nums[i] <= nums[i+1]) {
        //         right[i] = right[i+1] + 1;
        //     }
        // }

        // for (int i=k; i<n-k; i++) {
        //     if (min(left[i-1], right[i+1]) >= k-1) {
        //         ans.push_back(i);
        //     }
        // }

        // return ans;
    }
};