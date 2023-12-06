class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> count(5001, 0);

        // count all elements
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        // put the larger half of elements on even positions
        // notice that we start from the largest element and continue to the median
        int idx = count.size() - 1;
        for(int i = 1; i < nums.size(); i+=2) {
            while(count[idx] == 0) {
                idx--;
            }
            
            nums[i] = idx;
            count[idx]--;
        }

        // put the smaller half of elements on odd positions
        // notice that we start from median and continue to the smallest element
        for(int i =  0; i < nums.size(); i+=2) {
            while(count[idx] == 0) {
                idx--;
            }

            nums[i] = idx;
            count[idx]--;
        }
    }
};