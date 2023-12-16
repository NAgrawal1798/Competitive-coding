class Solution {
public:
    // 2 pointer approach and dp
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {

       int max_index=-1;
       int min_index=-1;
       int maxi = INT_MIN;
       int mini = INT_MAX;

       int n = nums.size();

       if ((n - indexDifference) < 0) {
           return {-1, -1};
       }

       for(int i=0; i<n - indexDifference; i++) {
           if (nums[i] < mini) {
               mini = nums[i];
               min_index = i;
           }
           if (nums[i] > maxi) {
               maxi = nums[i];
               max_index = i;
           }

           if (abs(nums[i+indexDifference] - mini) >= valueDifference) {
               return {i+indexDifference, min_index};
           }
           if (abs(nums[i+indexDifference] - maxi) >= valueDifference) {
               return {i+indexDifference, max_index};
           }
       }
       return {-1, -1};

        // vector<int>ans;

        // int n = nums.size();

        // for (int i=0; i<n; i++){
        //     bool flag=false;
        //     for (int j=i;j<n;j++) {
        //         if (abs(i-j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if (flag) {
        //         break;
        //     }
        // }

        // if (ans.size() == 0) {
        //     return {-1,-1};
        // }
        // return ans;
    }
};