class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // I want a data structure that can pop the elements
        // from front and push it from the back
        // reason to pick deque
        deque<int>dq;
        vector<int>res;
        for(int i=0; i<nums.size(); i++) {
            // before it remove the small elements
            if(dq.front() == i-k) {
                dq.pop_front();
            }
            // we are storing indices in dq
            // while nums[last_indice_stored] < nums[i], we will have to pop the last element
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i); // pushing index
            if( i>= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};