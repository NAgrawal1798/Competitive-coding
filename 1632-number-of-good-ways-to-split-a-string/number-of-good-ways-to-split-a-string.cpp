class Solution {
public:
    int numSplits(string s) {
        int size = s.size();

        if (!size) {
            return 0;
        }

        vector<int>left(size);
        vector<int>right(size);

        left[0] = 1;
        right[size-1] = 1;

        set<char>customSet;
        customSet.insert(s[0]);
        for(int i=1; i<size; i++) {
            customSet.insert(s[i]);
            left[i] = customSet.size();
        }

        customSet.clear();
        customSet.insert(s[size-1]);
        for(int i=size-2; i>=0; i--) {
            customSet.insert(s[i]);
            right[i] = customSet.size();
        }

        int ans = 0;
        for (int i=0;i<size-1;i++) {
            if(left[i] == right[i+1]) {
                ans++;
            }
        }

        return ans;
    }
};