class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int c = i * i;
            for (int j = 1; j <= n; j++) {
                int b = j * j;
                int k = c - b;
                if (k> 0) {
                    int root = sqrt(k);

                    if (root * root == k && root <= n) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
