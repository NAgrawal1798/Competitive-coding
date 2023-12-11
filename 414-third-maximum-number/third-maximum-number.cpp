class Solution {
public:
    // Solve this question using priority_queue
    int thirdMax(vector<int>& nums) {
        // max_heap datastructure
        priority_queue<int, vector<int>, greater<int>>minHeap; // Return min element

        unordered_set<int>taken;

        for (int i=0; i<nums.size(); i++) {
            if (taken.count(nums[i])) {
                continue;
            }

            if (minHeap.size() == 3) {
                // If the element is greater then the top most element

                int x = minHeap.top();
                if (x < nums[i]) {
                    minHeap.pop();
                    taken.erase(x);
                    minHeap.push(nums[i]);
                    taken.insert(nums[i]);
                }
            } else {
                minHeap.push(nums[i]);
                taken.insert(nums[i]);
            }
        }

        // nums has only one distinct element
        if (minHeap.size() == 1) {
            return minHeap.top();
        } else if (minHeap.size() == 2) {
            int firstNum = minHeap.top();
            minHeap.pop();
            return minHeap.top();
        }

        return minHeap.top();
    }
};