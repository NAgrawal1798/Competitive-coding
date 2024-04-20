class Solution {
public:
    // Solve this question using priority_queue
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size();
        set<int>s;
        for(int i=0; i<n; i++) {
            if(s.count(nums[i]) > 0) {
                continue;
            } else {
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
        }

        if(pq.size() < 3) {
            int ans = pq.top();
            return ans;
        }
        int k=3;
        while(k>1 ) {
            pq.pop();
            k--;
        }

        int ans = pq.top();
        return ans;
    }
};