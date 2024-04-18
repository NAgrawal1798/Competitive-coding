class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int n = nums.size();
        set<int>st;
        for(int i=0; i<n; i++) {
            if(st.count(nums[i]) > 0) {
                continue;
            } else {
                nums[k++] = nums[i];
                st.insert(nums[i]);
            }
        }

        return st.size();
    }
};