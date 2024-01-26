class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>res(n);
        sort(nums1.begin(), nums1.end());
        vector<pair<int,int>>p;

        for(int i=0; i<n; i++) {
            p.push_back({nums2[i], i});
        }

        sort(p.begin(), p.end());

        int fp=0, lp=n-1;

        for(auto i: nums1) {
            if(p[fp].first < i) {
                res[p[fp++].second] = i;
            } else {
                res[p[lp--].second] = i;
            }
        }

        return res;
    }
};