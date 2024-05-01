class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char>s;
        int ans =0 ;
        for(int i=0; i<jewels.size(); i++) {
            s.insert(jewels[i]);
        }
        for(int i=0; i<stones.size(); i++) {
            char c = stones[i];
            if(s.count(c) > 0) {
                ans++;
            }
        }

        return ans;
    }
};