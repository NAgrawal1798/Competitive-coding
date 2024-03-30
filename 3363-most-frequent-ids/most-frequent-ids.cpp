class Solution {
public:
    // most frequent means it is using greedy with priority queue
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        // multiset
        multiset<pair<long long, long long>, greater<pair<long long, long long>>> st; // multiset with pair
        map<long long, long long>mp;
        vector<long long>ans;
        long long n = nums.size();
        for(long long i=0; i<n; i++) {
                long long oldfq = mp[nums[i]];
                mp[nums[i]] += freq[i];
                long long newfq = mp[nums[i]];
                st.erase({oldfq, nums[i]}); // remove it from multiset
                if(newfq > 0) { // insert it again with new frequency
                    st.insert({newfq, nums[i]});
                }
                if(st.empty()) {
                    ans.push_back(0);
                } else {
                    long long val = st.begin()->first;
                    ans.push_back(val);
                }
        }
        return ans;
    }
};