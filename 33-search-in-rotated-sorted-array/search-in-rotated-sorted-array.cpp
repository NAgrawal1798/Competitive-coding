class Solution {
public:
    int pivot(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return -1;
        }
        
        int mid = low + (high - low) / 2;
        
        if (mid < high && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        if (mid > low && nums[mid] < nums[mid - 1]) {
            return mid - 1;
        }
        
        if (nums[mid] < nums[low]) {
            return pivot(nums, low, mid - 1);
        }
        if (nums[mid] > nums[high]) {
            return pivot(nums, mid + 1, high);
        }
        
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
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
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        
        int pivotIndex = pivot(nums, 0, n - 1);
        if (pivotIndex == -1) {
            return binarySearch(nums, target, 0, n - 1);
        }
        
        if (nums[pivotIndex] == target) {
            return pivotIndex;
        }
        
        if (nums[0] <= target) {
            return binarySearch(nums, target, 0, pivotIndex);
        } else {
            return binarySearch(nums, target, pivotIndex + 1, n - 1);
        }
    }
};
