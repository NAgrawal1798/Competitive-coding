class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>prime(n+1, true);
        prime[0] = prime[1] = false;
        for(int i=2; i<=n; i++ ) {
            if (prime[i] && (long long)i*i <= n) {
                for(int j=i*i; j<=n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        vector<vector<int>>v;
        if(n==1) {
            return v;
        }

        for(int i=2; i<=n/2; i++) {
            if(prime[i] && prime[n-i]) {
                vector<int>temp;
                temp.push_back(i);
                temp.push_back(n-i);
                v.push_back(temp);
            }
        }

        return v;
    }
};