class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int,int>mp;

        int n = arr.size();
        for (int i=0; i<n; i++) {
            mp[arr[i]] = i;
        }

        int m = pieces.size();
        for (int i=0; i<m; i++) {
            if (pieces[i].size() ==  1) {
                if ((mp.find(pieces[i][0]) == mp.end())) {
                        return false;
                    }
            }
            if (pieces[i].size() > 1) {
                int size = pieces[i].size();

                for (int j=0; j<size-1; j++) {
                    if ((mp.find(pieces[i][j]) == mp.end()) || (mp.find(pieces[i][j+1]) == mp.end())) {
                        return false;
                    }
                    if (mp[pieces[i][j+1]] - mp[pieces[i][j]]  > 1) {
                        return false;
                    }
                    if (mp[pieces[i][j]] > mp[pieces[i][j+1]]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};