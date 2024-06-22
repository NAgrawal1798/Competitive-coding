class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while(low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
    int findPivot(vector<int>& nums, int low, int high) {
        if(high <= low) {
            return -1;
        }
        int mid = low + (high - low)/2;
        if (mid > low && nums[mid] < nums[mid - 1]) {
            return mid - 1;
        }
        if (mid < high && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        // right half
        if (nums[mid] < nums[low]) {
            return findPivot(nums, low, mid - 1);
        } else {
            return findPivot(nums, mid + 1, high);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // find the pivot element
        int n = nums.size();
        int pivot = findPivot(nums, 0, n-1);

        if (pivot == -1) {
            return binarySearch(nums, target, 0, n-1);
        }

        if (nums[pivot] == target) {
            return pivot;
        }
        // find binary search
        if (nums[0] <= target) {
            return binarySearch(nums, target, 0, pivot);
        } else {
            return binarySearch(nums, target, pivot+1, n - 1);
        }

    }
};