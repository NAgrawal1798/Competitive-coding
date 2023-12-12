class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        vector<int>ans;
        int start = -1;
        int end = -1;

        while(i<=j) {
            int mid = (i+j)/2;
            if (nums[mid] == target) {
                            cout<<mid<<endl;

                int startingMid = mid;
                int endingMid = mid;
                while(startingMid >= 0 && nums[startingMid] == target) {
                    startingMid--;
                }
                start = startingMid + 1;
                while(endingMid <= n-1 && nums[endingMid] == target) {
                    endingMid++;
                }
                end = endingMid - 1;
                break;
            } else if (nums[mid] > target) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }

        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};