class Solution {
public:
    // dp solution
    map<long long,long long >mp;
    long long  helper(long long  n) {
        if(n<=1) {
            return mp[n] = 0;
        }
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        int count=0;
        if (n%2==0) {
            count = 1 + helper(n/2);
        } else {
            count = 1 + min(helper(n-1), helper(n+1)); 
        }
        return mp[n] = count;
    }
    int integerReplacement(int n) {
        helper(n);
        return mp[n];
    }
};