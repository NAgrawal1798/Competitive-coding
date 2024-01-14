#include <vector>
#include <algorithm> // Include algorithm for sort function

class Solution {
public:
    bool helper(const std::vector<int>& candies, int mid, long long k) {
        long long ans = 0;
        for (int i = 0; i < candies.size(); i++) {
            ans += candies[i]/mid;
        }
        return ans >= k;
    }

    int maximumCandies(std::vector<int>& candies, long long k) {
        int low = 1; // Start from 0 instead of 1
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(candies, mid, k)) {
                ans = mid;
                low = mid + 1; // Update low to mid + 1
            } else {
                high = mid-1;
            }
        }
        return ans; // Return low - 1 since we are looking for the last possible value
    }
};
