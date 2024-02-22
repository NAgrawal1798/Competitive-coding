class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
       vector<int>dr = {-1, -1, -1, 0, 1, 1, 1, 0};
       vector<int>dc = {-1, 0, 1, 1, 1, 0, -1, -1};

       map<pair<int,int>, bool>mp;
       for (auto it: queens) {
           int x = it[0];
           int y = it[1];
           mp[{x, y}] = true;
       }
        
        vector<vector<int>>ans;
        int kr = king[0];
        int kc = king[1];
       for (int i=0; i<8; i++) {
           int newr = kr + dr[i];
           int newc = kc + dc[i];
           while(newr >= 0 && newr < 8 && newc >= 0 && newc <8) {
               if (mp.find({newr , newc}) != mp.end()) {
                   vector<int>temp;
                   temp.push_back(newr);
                   temp.push_back(newc);
                   ans.push_back(temp);
                   break;
               }
               newr = newr + dr[i];
               newc = newc + dc[i];
           }
       }

       return ans;
    }
};