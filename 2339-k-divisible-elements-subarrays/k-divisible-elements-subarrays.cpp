class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>s;
        
        int n = nums.size();
        for (int i=0; i<n; i++) {
            vector<int>v;
            for (int j=i; j<n; j++) { 
                    v.push_back(nums[j]);
                    int count=0;
                    for (int k=0; k< v.size(); k++) {
                        if (v[k]%p==0) {
                            count++;
                        }
                    }

                    if (count<=k) {
                        s.insert(v);
                }
            }
        }

        return s.size();
    }
};