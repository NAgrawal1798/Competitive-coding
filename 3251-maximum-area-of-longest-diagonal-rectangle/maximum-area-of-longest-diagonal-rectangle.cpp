class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        map<double,vector<int>>mp;

        int n = dimensions.size();
        for(int i=0; i<n; i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            double sq = sqrt(length*length + width*width);
            mp[sq].push_back(length*width);
        }

        double largestDia = 0;
        for(auto it: mp) {
            if(it.first > largestDia) {
                largestDia = it.first;
            }
        }

        vector<int>area = mp[largestDia];
        sort(area.begin(), area.end(), greater<int>());
        return area[0];

    }
};