class Solution {
public:
    int halveArray(vector<int>& nums) {
        // use priority queue to store elements in descending order.
        // so biggest element is always on top of queue
        priority_queue<double>pq;
        int n = nums.size();
        double sum = 0; // total sum of element

        // store all elements in priority queue
        for(int i=0; i<n; i++) {
            pq.push(nums[i]);
            sum += nums[i];
        }

        // half of total
        double half = sum/2;
        int operation = 0;

        while(sum > half) {
                double maxi = pq.top();
                pq.pop();
                maxi /= 2;
                pq.push(maxi);
                sum -= maxi;
                operation++;
        }

        return operation;
    }
};