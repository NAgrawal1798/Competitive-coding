class Solution {
public:
    long long ans = INT_MAX;
    void solve(vector<int>&cookies, vector<long long>&child, int k, int i, long long maxCurr) {
        if(i == cookies.size()) {
            ans = min(ans, maxCurr);
            return;
        }
        long long curr = maxCurr;
        for(int j=0; j<k; j++) {
            child[j] += (long long)cookies[i];
            solve(cookies , child , k , i+1 , max(curr , child[j]));
            child[j] -= (long long)cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<long long>child(k, 0);
        solve(cookies, child, k, 0, 0);
        return ans;
    }
};