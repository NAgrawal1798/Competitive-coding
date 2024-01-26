class Solution {
public:
    // merge algo
    void merger(vector<int>&nums, int start, int end) {
        // define left array and right array lengths
        int mid = start + (end-start)/2;
        int leftLen = mid - start+1;
        int rightLen = end-mid;


        //create left array and right array
        vector<int>leftArray(leftLen);
        vector<int>rightArray(rightLen);

        int k =start;

        // copy values from left array
        for(int i=0;i<leftLen; i++) {
            leftArray[i] = nums[k++];
        }

        // copy values from right array
        for(int i=0; i<rightLen; i++) {
            rightArray[i] = nums[k++];
        }

        // merge both leftarray and rightarray
        int leftInd=0;
        int rightInd=0;
        int mainInd = start;
        while(leftInd < leftLen && rightInd<rightLen) {
            if(leftArray[leftInd] < rightArray[rightInd]) {
                nums[mainInd++] = leftArray[leftInd++];
            } else {
                nums[mainInd++] = rightArray[rightInd++];
            }
        }

//add remaining elements of left array to main array
        while(leftInd < leftLen){
            nums[mainInd++] = leftArray[leftInd++];
        }

        //add remaining elements of right array to main array
        while(rightInd < rightLen){
            nums[mainInd++] = rightArray[rightInd++];
        }


    }
    // merge sort
    void mergeSort(vector<int>&nums, int start, int end) {
        // base case
        if(start>=end) {
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(nums,start, mid);
        mergeSort(nums,mid+1,end);

        merger(nums,start, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        mergeSort(nums, start, end);
        return nums;
    }
};