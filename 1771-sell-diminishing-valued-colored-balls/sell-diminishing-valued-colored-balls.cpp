class Solution {
public:
    // Solution in O(logn) using binary search

    long long get_orders(vector<int>& inv, int val) {
        long long o = 0;
        for (auto i: inv) {
            o += max(0, i-val);
        }
        return o;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        long long res = 0;
        long long kMod = 1'000'000'000 + 7;

        long long low = 0;
        long long high = 1'000'000'000;

        while(low <= high) {
            auto mid = (low + high)/2;
            auto temp = get_orders(inventory, mid);
            if (temp > orders) {
                low = mid+1;
            } else if (temp == orders) {
                low = mid;
                break;
            } else {
                high = mid - 1;
            }
        }

        for(long long i: inventory) {
            if(i > low) {
                res += (i-low) * (i + low + 1LL) /2;
                res %= kMod;
                orders -= (i-low);
                orders = max(0, orders);
            }
        }

        return (res + low*orders)%kMod;
    }
};