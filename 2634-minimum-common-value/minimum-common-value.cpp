class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;

       
        int n = nums1.size();
        int m = nums2.size();
        int i=n-1;
        int j=m-1;

        while(i>=0 && j>=0) {
          if (nums1[i] == nums2[j]) {
            ans = min(nums1[i], ans);
            i--;
            j--;
          } else if (nums1[i] < nums2[j]) {
            j--;
          } else {
            i--;
          }
        }

        if (ans == INT_MAX) {
          return -1;
        }
        return ans;
    }
};