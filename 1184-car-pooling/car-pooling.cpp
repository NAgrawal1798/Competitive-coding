class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       multimap<int,int>map;
       for(int i=0;i<trips.size();i++){
         int cap=trips[i][0];
             map.insert(make_pair(trips[i][1],-cap));
             map.insert(make_pair(trips[i][2],cap));
       }
           for (auto i = map.begin(); i != map.end(); i++){
                capacity=capacity+i->second;
                  auto z=i;
                  ++z;
// the main part comes here because for a  particular interval we  
   //   have to check until the next value is not same 
                if(capacity < 0 && i->first != z->first) return false;
           }    
       return true;
    }
};