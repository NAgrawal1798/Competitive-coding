class TopVotedCandidate {
private:
    vector<pair<int,int>>candidates;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_count=0;
        int len = persons.size();
        map<int,int>mp;
        int candidate = 0;

        for (int i=0; i< len; i++) {
            mp[persons[i]]++;
            if (mp[persons[i]] >= max_count) {
                max_count =mp[persons[i]];
                candidate = persons[i];
            }
            candidates.push_back({times[i], candidate});
        }
    }
    
    int q(int t) {
        int lo = 0;
        int hi = candidates.size();
        while(lo < hi) {
            int m = lo + (hi-lo)/2;
            if (candidates[m].first <= t) {
                lo = m+1;
            } else {
                hi = m;
            }
        }
        return candidates[lo-1].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */