class DataStream {
public:
   // variables
   deque<int>dq;
   unordered_map<int,int>mp;
   int value;
   int k;
    DataStream(int value, int k) {
       this -> value = value;
       this -> k = k;
       dq.clear();
       mp.clear();
    }
    
    bool consec(int num) {
        mp[num]++; // add number in map
        dq.push_back(num); // add number in deque
        bool ans = (mp.size() == 1 && dq.size() == k && num == value);
        if(dq.size() == k) { // remove the first element here
            int front = dq.front(); 
            dq.pop_front();
            mp[front]--;
            if(mp[front] == 0) { // remove key from map if frequency is zero
                mp.erase(front);
            }
        }

        return ans;
    }
};