class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>resV; // result vector to store the pairs
        // min heap priority queue to store the pairs with smallest sums, sorted by sums
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        // Push the initial pairs into the priority queue
        for(int x: nums1) {
            pq.push({x + nums2[0], 0}); //the sum and the index of the second element in nums2
        }

        //Pop the k smallest pairs from the priority queue
        while(k--) {
            int sum = pq.top().first; // get the smallest sum
            int pos = pq.top().second; // get the index of the second element in nums2

            resV.push_back({sum - nums2[pos], nums2[pos]});
            pq.pop();

            // If there are more elements in nums2, push the next pairs into the priority queue
            if(pos+1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos+1], pos+1});
            }
        }

        return resV;
    }
};