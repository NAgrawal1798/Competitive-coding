class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // use priority queue
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            pq.push(nums[i]);
        }

        int count=0;
        while(pq.top() < k) {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            long long newNumber = min(num1, num2)*2 + max(num1, num2);
            pq.push(newNumber);
            count++;
        }

        return count;
    }
};