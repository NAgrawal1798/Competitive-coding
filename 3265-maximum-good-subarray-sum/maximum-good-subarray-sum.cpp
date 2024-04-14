class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    //   int n = nums.size();

    //   unordered_map<int, vector<int>>mp;

    //   vector<long long>sum(n);

    //   for(int i=0; i<n; i++) {
    //     mp[nums[i]].push_back(i);
    //     if(i==0) {
    //         sum[i] = nums[i];
    //     } else {
    //         sum[i] = nums[i] + sum[i-1];
    //     }
    //   }

    //   double mx = LONG_MIN + 100;
    //   for(int i=0; i<n; i++) {
    //     int target = nums[i] + k;

    //     for(auto ind: mp[target]) {
    //         if(ind > i) {
    //             mx = max(mx, (double)sum[ind] - sum[i] + nums[i]);
    //         }
    //     }


    //     target = nums[i] - k;
    //     for(auto ind: mp[target]) {
    //         if(ind > i) {
    //             mx = max(mx, (double)sum[ind] - sum[i] + nums[i]);
    //         }
    //     }
    //   }
    //   if(mx == LONG_MIN + 100) {
    //     return 0;
    //   }
    //   return mx;
    // }

    int n = nums.size();
    unordered_map<long long, long long>mp;
    vector<long long>sum(n);

    sum[0] = nums[0];
    mp[nums[0]] = sum[0];

    long long ans = LLONG_MIN;

    for(int i=1; i<n; i++) {
        // prefix sum
        sum[i] = sum[i-1] + nums[i];

        auto it = mp.find(nums[i]);
        if(it != mp.end()) {
            mp[nums[i]] = min(sum[i], mp[nums[i]]);
        } else {
            mp[nums[i]] = sum[i];
        }

        // target 1 = nums[i] + k
        it = mp.find(nums[i] + k);
        if(it!= mp.end()) {
            ans = max(ans, sum[i] - mp[nums[i] + k] + nums[i] + k);
        }

        it = mp.find(nums[i] - k);
        if(it != mp.end()) ans = max(ans, sum[i] - mp[nums[i] - k] + nums[i] - k);
    }

    if(ans == LLONG_MIN) return 0;
    return ans;

    }
};