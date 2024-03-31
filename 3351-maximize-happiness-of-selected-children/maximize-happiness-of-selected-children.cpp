class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        // every time i have to find the biggest element - this thought is keep 
        // pushing me towards to use the priority queue

        // and i have to reduce the values again and again
        // by 1

        // as this is kind of a greedy approch
        // so sorting will work here

        sort(h.begin(), h.end(), greater<int>());
        int sub = 0;
        long long ans = 0;
        int i=0;
        while(k--) {
            if(h[i] - sub >= 0) {
                ans += h[i++] - sub;
            }
            sub++;
        }

        return ans;
    }
};