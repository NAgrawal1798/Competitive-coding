class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i=0; i<intervals.size(); i++) {
            // if ans is empty and there is no overlapping
            if(ans.size() == 0 || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }

        return ans;
    }
};