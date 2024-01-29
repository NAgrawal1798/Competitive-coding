class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count_map;
        vector<int> res;

        for(auto& n: nums){
            count_map[n]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto& [key,value]: count_map){
            bucket[value].push_back(key);
        }

        for(int i= bucket.size()-1; i>=0; i--){
            for(auto n: bucket[i]){
                if(k>0){
                    res.push_back(n);
                    k--;
                }
            }
        }
        return res;
    }
};