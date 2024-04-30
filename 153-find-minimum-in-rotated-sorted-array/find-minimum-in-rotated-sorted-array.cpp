class Solution {
public:
    int findPivot(vector<int>& arr, int low, int high)
{
    // Base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    // low + (high - low)/2;
    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pivot = findPivot(nums, 0, n - 1);
 
        // If we didn't find a pivot,
        // then array is not rotated at all
        if (pivot == n-1) {
            return nums[0];
        }
        if(n == 1) {
            return nums[0];
        }

        return nums[pivot+1];

    }
};